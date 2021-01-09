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

	// Draw 4 squares in the image
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x < width / 2)
				if (y < height / 2)
					// Top left is Red
					SetPixelV(img, x, y, RGB(255, 0, 0));
				else
					// Bottom left is Green
					SetPixelV(img, x, y, RGB(0, 255, 0));
			else
				if (y < height / 2)
					// Top Right is Blue
					SetPixelV(img, x, y, RGB(0, 0, 255));
				else
					// Bottom right is White
					SetPixelV(img, x, y, RGB(255, 255, 255));
		}
	}
}