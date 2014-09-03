#include "rgbapixel.h"


RGBAPixel::RGBAPixel() //constructor (using scope thing)
{
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
}

RGBAPixel::RGBAPixel(uint8_t R, uint8_t B, uint8_t G)
{
	red = R;
	blue = B;
	green = G;
	alpha = 255;
}


