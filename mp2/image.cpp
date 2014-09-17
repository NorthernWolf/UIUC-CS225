//copied this stuff over from png.cpp
#include <cstdint>

#include "image.h" //need to include header file

using std::uint8_t;


//let's implement some functions!

void Image::flipleft()
{
	
	size_t i;
	size_t j;

	for(i = 0 ; i < width()/2 ; i++) //loop through each x pixels (only up to the middle one!)
	{
		for(j = 0; j < height() ; j++) //go through every line
		{
		//super similar to mp1..we need to swap pixels
		//they want us to use a temporary variable to swap images
		//declare the temp variable
		//width() and height() defined in PNG.h
		RGBAPixel temp = *(*this)(i,j); // '*this' is the object that is invoking the function
		//now lets make a swap
		//temp = target, target = temp
		*(*this)(i,j) = *(*this)(width()-1-i, j); //need to subtract 1 becasue otherwise we'd go to 257th element
		*(*this)(width()-1-i, j) = temp; //finish the swap.  

		}
	}


}


void Image::adjustbrightness(int r, int g, int b)
{
	


	for(size_t i=0 ; i < width() ; i++) //loop through each x pixel
	{
		for(size_t j=0; j < height() ; j++) //go through every line
		{
			RGBAPixel * pixel = (*this)(i,j); //define our pixel pointer
			
			if(pixel->red + r >255) 
			{
				pixel->red = 255;//if its over 255 just set it to 255
			}
			else if(pixel->red +r <0)
			{
				pixel->red = 0; //if its less than zero, set it equal to zero
			}
			else
			{
				pixel->red += r;//if we didn't go over or under, then just increase appropriately
			}
			//now we just repeat this thing for g and b
			
			if(pixel->green + g > 255) 
			{
				pixel->green = 255;//if its over 255 just set it to 255
			}
			else if(pixel->green +g < 0)
			{
				pixel->green = 0; //if its less than zero, set it equal to zero
			}
			else
			{
				pixel->green += g;//if we didn't go over or under, then just increase appropriately
			}
			//green above..here's blue:
			if(pixel->blue + b > 255) 
			{
				pixel->blue = 255;//if its over 255 just set it to 255
			}
			else if(pixel->blue +b < 0)
			{
				pixel->blue = 0; //if its less than zero, set it equal to zero
			}
			else
			{
				pixel->blue += b;//if we didn't go over or under, then just increase appropriately
			}
		}
	}

}



void Image::invertcolors()
{


	for(size_t i=0 ; i < width() ; i++) //loop through each x pixel
		{
		for(size_t j=0; j < height() ; j++) //go through every line
		{
				RGBAPixel * pixel = (*this)(i,j); //define our pixel pointer
				pixel->red = 255 - pixel->red;//make the red 255 - its original value
				pixel->green = 255 - pixel->green;//make the green 255 - its orignal value
				pixel->blue = 255 - pixel->blue;//make the blue 255 - its orignal value
		}
	}
}


