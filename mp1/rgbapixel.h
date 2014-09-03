#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H
#include <cstdint>
#include <iostream>


using std::uint8_t;


class RGBAPixel{

	public:

	//members:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

	RGBAPixel(); //constructor
	RGBAPixel(uint8_t red, uint8_t green, uint8_t blue);


	
	

};

#endif 	
