#include "draw.h"
#include <iostream>

/////////////////
// Function   : draw()
// Parameters : int width		number of columns
//              int height		number of rows
//              HDC &img		windows image buffer
//				Scene scene		information about the scene (see scene.h)
//
/////////////////
void draw(
	int width,
	int height,
	HDC &img,
	Scene scene)
{
	std::vector<vec4f> face;
	face.resize(3);
	float r, g, b;
	float x0, x1, y;
	float DeltaX0, DeltaX1;

	// Copy faces into mutable vector
	// Sort faces by depth

	// DRAW FACE
	for (int i = 0; i < scene.model.face.size(); i++) {

		// Read face color
		r = scene.model.faceColor.at((scene.model.face.at(i).at(0))).x*255;
		g = scene.model.faceColor.at((scene.model.face.at(i).at(0))).y*255;
		b = scene.model.faceColor.at((scene.model.face.at(i).at(0))).z*255;

		// Make copy of vertices vector
		face.at(0) = scene.model.vertex.at(scene.model.face.at(i).at(0));
		face.at(1) = scene.model.vertex.at(scene.model.face.at(i).at(1));
		face.at(2) = scene.model.vertex.at(scene.model.face.at(i).at(2));

		// Sort vertices by y-position
		auto compareVertices = [](vec4f a, vec4f b) {
			return (a.y > b.y);
		};
		std::sort(face.begin(), face.end(), compareVertices);

		// Convert to graphics window coordinate system
		face.at(0).y = 800 - face.at(0).y;
		face.at(1).y = 800 - face.at(1).y;
		face.at(2).y = 800 - face.at(2).y;

		// Set starting scanline position
		x0 = face.at(0).x;
		x1 = face.at(0).x;
		y = face.at(0).y;

		// Set delta for longest side
		DeltaX0 = (face.at(0).x - face.at(2).x) / (face.at(0).y - face.at(2).y);

		if (face.at(0).y != face.at(1).y) { // Check for horizontal edge
			// Set second delta for upper half
			DeltaX1 = (face.at(0).x - face.at(1).x) / (face.at(0).y - face.at(1).y);
			// Draw upper triangle
			while (y < face.at(1).y) {
				for (int x = min(x0, x1); x < max(x0, x1); x++)
					SetPixelV(img, floor(x), floor(y), RGB(r, g, b));
				x0 += DeltaX0;
				x1 += DeltaX1;
				y++;
			}
		}
		else {
			x1 = face.at(1).x;
		}
		
		if (face.at(1).y != face.at(2).y) { // Check for horizontal edge
			// Set second delta for lower half
			DeltaX1 = (face.at(1).x - face.at(2).x) / (face.at(1).y - face.at(2).y);
			// Draw lower triangle
			while (y < face.at(2).y) {
				for (int x = min(x0, x1); x < max(x0, x1); x++)
					SetPixelV(img, floor(x), floor(y), RGB(r, g, b));
				x0 += DeltaX0;
				x1 += DeltaX1;
				y++;
			}
		}
		
		
	}
}