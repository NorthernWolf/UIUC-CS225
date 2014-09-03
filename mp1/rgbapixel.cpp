#include "rgbapixel.h"


RGBAPixel::RGBAPixel() //constructor (using scope thing)
{
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
}
RGBAPixel::RGBAPixel(uint8_t Nred, uint8_t Nblue, uint8_t Ngreen)
{
	red = Nred;
	blue = Nblue;
	green = Ngreen;
	alpha = 255;
}


