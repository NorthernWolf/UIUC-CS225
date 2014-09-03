#include "rgbapixel.h"


RGBAPixel::RGBAPixel() //constructor (using scope thing)
{
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
}

RGBAPixel::RGBAPixel(uint8_t newRed, uint8_t newBlue, uint8_t newGreen)
{
	red = newRed;
	blue = newBlue;
	green = newGreen;
	alpha = 255;
}


