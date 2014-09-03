#include <algorithm> //using the same includes as the lab 
#include <iostream>
#include "rgbapixel.h"
#include "png.h"

using namespace std; //also in lab main file

/*
Program in main uses functions from EasyPNG library to open a bitmap image named in.png, 
rotate the image by 180 degrees, and write the resulting image to the file out.png.
*/

int main()
{

PNG inputimage("in.png");// Open a new PNG called inputimage from the file in.png.



PNG outputimage(inputimage.width(), inputimage.height());//created a new PNG called outputimage with height and width of input image

int i;//initialize i
int j;//initialize j		

cout<< "width is: " << inputimage.width()<< endl; //tests to make sure everything is working
cout<< "height is: " << inputimage.height()<< endl ;
cout<< "had to change i and j to just int from uint8_t for it to work"<< endl;
cout<< "why am i getting an error on the autorgrader test 2"<< endl;

	for(i = 0; i < inputimage.width() ; i++ ) //go through every pixel along the x axis 
	{
		for(j = 0; j < inputimage.height() ; j++)//go through every pixel along the y axis
		{
			//we need to assign pixels "opposite values"

			//using this function from png.h:
			//(video on operator() helped alot 

	//RGBAPixel * operator()(size_t x, size_t y);

        /***
         * Const pixel access operator. Const version of the previous
         * operator(). Does not allow the image to be changed via the
         * pointer.
         * @param x X-coordinate for the pixel pointer to be grabbed from.
	     * @param y Y-cooridnate for the pixel pointer to be grabbed from.
         * @return A pointer to the pixel at the given coordinates (can't
         *change the pixel through this pointer).
		*/

			*outputimage.operator()(inputimage.width() -1 -i, inputimage.height()-1-j) = *inputimage.operator()(i,j);
			//
			//above line of code sets each point in outputimage to be the exact opposite of that in inputimage
			//we need the -1 becasue we start for loop at zero and go to the maximum value (256) so we'd be doing one more than the max value
			//.. can't start for loops at 1 becasue image starts at zero!
		}

	}


outputimage.writeToFile("out.png"); // Save the modified image to a file called out.png, 										//overwriting the file if it already exists.

return 0;


}


