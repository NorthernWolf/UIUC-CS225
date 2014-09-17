#ifndef IMAGE_H
#define IMAGE_H

//copied all this over from png.h

// c-style includes
#include <stdio.h>
#include <stdlib.h>
#include <png.h>

// c++ style includes
#include <string>
#include <iostream>
#include <sstream>

// local includes
#include "png.h"

using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

//making the image subclass of PNG
class Image : public PNG
{

	public:

		void flipleft(); //Flips the image about a vertical line through its center by swapping pixels
						//be careful with memory on this guy



		void adjustbrightness(int r, int g, int b);//adds to the red, green, and blue parts of each pixel of the image
													//overflow prevented

		
		void invertcolors(); //makes each RGB component of each pixel equal to 255 minus its original value
	
		//does this thing need its own constuctor and destructor
			
		//Image(); //constructor
		//~Image();//destructor




};

#endif
