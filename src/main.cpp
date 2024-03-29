#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

/*

void bresenLine(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
	for (float i = 0.0f; i <= 1.0f; i += 0.1f)
	{
		int x = x0 + (x1 - x0) * i;
		int y = y0 + (y1 - y0) * i;

		image.set(x, y, color);
	}
}

*/

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
	bool steep = false;
	if (std::abs(x0 - x1) < std::abs(y0 - y1))
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	}
	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	for (int x = x0; x <= x1; x++)
	{
		float t = (x - x0) / (float)(x1 - x0);
		int y = y0 * (1. - t) + y1 * t;
		if (steep)
		{
			image.set(y, x, color);
		}
		else
		{
			image.set(x, y, color);
		}
	}
}

int main(int argc, char* argv[])
{
	TGAImage image(100, 100, TGAImage::RGB);
	//image.set(100, 100, red);
	line(0, 0, 50, 50, image, red);
	//image.set(52, 41, red);
	image.flip_vertically();
	image.write_tga_file("output.tga");
	return 0;
}
