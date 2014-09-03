#include "rgbapixel.h"


RGBAPixel::RGBAPixel() //constructor (using scope thing)
{
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
}

RGBAPixel::RGBAPixel(uint8_t newRed, uint8_t newGreen, uint8_t newBlue)
{
	red = newRed;
	green = newGreen;
	blue = newBlue;
	alpha = 255;
}


