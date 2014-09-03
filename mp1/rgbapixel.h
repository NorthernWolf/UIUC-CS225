#include <cstdint>
#include <ostream>
#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H


using std::uint8_t;


class RGBAPixel{

	public:


	RGBAPixel(); //constructor
	RGBAPixel(uint8_t red, uint8_t blue, uint8_t green);


	//members:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

};

#endif 	
