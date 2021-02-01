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
	std::vector<int> currentFace;

	// For each face...
	for (int i = 0; i < scene.model.face.size(); i++) {

		SetPixelV(img, 5, 5, RGB(0, 255, 0));

		// ... sort indices of vertices
		currentFace = scene.model.face.at(i);
		std::sort(currentFace.begin(), currentFace.end()); // How do I check whether this is the correct order?
		vec4f high = scene.model.vertex.at(currentFace.at(0));
		vec4f low = scene.model.vertex.at(currentFace.at(2));
		vec4f mid = scene.model.vertex.at(currentFace.at(1));

		high.y = 800 - high.y;
		mid.y  = 800 - mid.y;
		low.y  = 800 - low.y;

		float dy = 1;

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
			// ...fill each scanline.

			x0 += DeltaX0;
			x1 += DeltaX1;
			y++;
		}

		// Update second delta for lower half
		DeltaX1 = (mid.x - low.x) / (mid.y - low.y);

		// For lower half...
		while (y <= low.y) {
			// ...fill each scanline.
			x0 += DeltaX0;
			x1 += DeltaX1;
			y++;
		}

	}

	// Draw 4 squares in the image

	//			else
	//				// Bottom left is Green
	//				SetPixelV(img, x, y, RGB(0, 255, 0));
	//		else
	//			if (y < height / 2)
	//				// Top Right is Blue
	//				SetPixelV(img, x, y, RGB(0, 0, 255));
	//			else
	//				// Bottom right is White
	//				SetPixelV(img, x, y, RGB(255, 255, 255));
	//	}
	//}
}