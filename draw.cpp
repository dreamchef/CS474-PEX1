#include "draw.h"


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
	for(int i = 0; i < scene.model.face.size(); i++) {
		
		// ... sort indices of vertices.
		currentFace = scene.model.face.at(i);
		std::sort(currentFace.begin(), currentFace.end());

		// Test for special cases

		// calculate line between highest and lowest vertices
		// save as appropriate side

		// Calculate line between upper two vertices.
		// save as appropriate side

		// LOOP: Draw horizontal lines pairwise down to middle vertex...

			// ... using lines to calculate start/end.

		// Calculate line between lower two vertices.
		// update appropriate side

		// LOOP: Draw horizontal lines pairwise down to lowest vertex...

			// ... using lines to calculate start/end.
		}









	// Draw 4 squares in the image
	//for (int y = 0; y < height; y++)
	//{
	//	for (int x = 0; x < width; x++)
	//	{
	//		if (x < width / 2)
	//			if (y < height / 2)
	//				// Top left is Red
	//				SetPixelV(img, x, y, RGB(255, 0, 0));
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