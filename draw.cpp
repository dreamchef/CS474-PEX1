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
	
	// For each face...
	for (int i = 0; i < scene.model.face.size(); i++) {

		// ... sort indices of vertices
		face.at(0) = scene.model.vertex.at(scene.model.face.at(i).at(0));
		face.at(0) = scene.model.vertex.at(scene.model.face.at(i).at(0));
		face.at(0) = scene.model.vertex.at(scene.model.face.at(i).at(0));

		auto compareVertices = [](vec4f a, vec4f b) {
			return (a.y > b.y);
		};

		std::sort(face.begin(), face.end(), compareVertices); // Check correct order
		
		vec4f high = face.at(0);
		vec4f low = face.at(1);
		vec4f mid = face.at(2);

		high.y = 800 - high.y;
		mid.y  = 800 - mid.y;
		low.y  = 800 - low.y;

		float dx;

		// Calculate delta for longest side
		float DeltaX0 = (high.x - low.x) / (high.y - low.y);

		// Calculate second delta for upper half
		float DeltaX1 = (high.x - mid.x) / (high.y - mid.y);

		// Starting scanline position
		float x0 = high.x;
		float x1 = high.x;
		float y = high.y;

		// For upper half...
		while (y <= mid.y) {
			for(int x = min(x0,x1); x < max(x0,x1); x++)
				SetPixelV(img, floor(x), floor(y), RGB(0, 255, 0));
			x0 += DeltaX0;
			x1 += DeltaX1;
			y++;
		}

		// Update second delta for lower half
		DeltaX1 = (mid.x - low.x) / (mid.y - low.y);

		// For lower half...
		while (y <= low.y) {
			for (int x = min(x0, x1); x < max(x0, x1); x++)
				SetPixelV(img, floor(x), floor(y), RGB(0, 255, 0));
			x0 += DeltaX0;
			x1 += DeltaX1;
			y++;
		}
	}

	//TODO: depth buffer, colors
}