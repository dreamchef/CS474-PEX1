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
	
	// For each face...
	for (int i = 0; i < scene.model.face.size(); i++) {

		// ... sort indices of vertices
		face.at(0) = scene.model.vertex.at(scene.model.face.at(i).at(0));
		face.at(1) = scene.model.vertex.at(scene.model.face.at(i).at(1));
		face.at(2) = scene.model.vertex.at(scene.model.face.at(i).at(2));

		auto compareVertices = [](vec4f a, vec4f b) {
			return (a.y > b.y);
		};

		std::sort(face.begin(), face.end(), compareVertices); // Check correct order

		face.at(0).y = 800 - face.at(0).y;
		face.at(1).y = 800 - face.at(1).y;
		face.at(2).y = 800 - face.at(2).y;

		// Calculate delta for longest side
		float DeltaX0 = (face.at(0).x - face.at(2).x) / (face.at(0).y - face.at(2).y);

		// Calculate second delta for upper half
		float DeltaX1 = (face.at(0).x - face.at(1).x) / (face.at(0).y - face.at(1).y);

		// Starting scanline position
		float x0 = face.at(0).x;
		float x1 = face.at(0).x;
		float y = face.at(0).y;

		// For upper half...
		while (y <= face.at(1).y) {
			for(int x = min(x0,x1); x < max(x0,x1); x++)
				SetPixelV(img, floor(x), floor(y), RGB(0, 255, 0));
			x0 += DeltaX0;
			x1 += DeltaX1;
			y++;
		}

		// Update second delta for face.at(2)er half
		DeltaX1 = (face.at(1).x - face.at(2).x) / (face.at(1).y - face.at(2).y);

		// For face.at(2)er half...
		while (y <= face.at(2).y) {
			for (int x = min(x0, x1); x < max(x0, x1); x++)
				SetPixelV(img, floor(x), floor(y), RGB(0, 255, 0));
			x0 += DeltaX0;
			x1 += DeltaX1;
			y++;
		}
	}

	//TODO: depth buffer, colors
}