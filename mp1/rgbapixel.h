#include <cstdint>
#include <ostream>
#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H





class RGBAPixel{

	public:


	RGBAPixel(); //constructor
	RGBAPixel(uint8_t newRed, uint8_t newBlue, uint8_t newGreen);


	//members:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

};

#endif 	
