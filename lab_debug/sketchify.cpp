#include <cstdlib>
#include <iostream> //had to add for cout
#include "png.h"


using namespace std;//had to add for cout

//
// sets up the output image
PNG * setupOutput(int w, int h)
{
	PNG * image = new PNG(w, h);
	return image;
}


// Returns my favorite color
RGBAPixel * myFavoriteColor(int intensity)
{
	RGBAPixel *color= new RGBAPixel;//color used to be local but now we've de referenced it and make it a default object
	color->red   = 0; //added pointer arrows
	color->green = intensity/2;//added pointer arrow
	color->blue  = intensity;//added pointer arrow
	return color;//took off the &
}


void sketchify()
{
	// Load in.png
	PNG * original;
	cout << "Reached line 28" << endl;//added print statement
	original = new PNG; //from lecture (9/3) we have to make a memory location for this object pointer
	original -> readFromFile("in.png");
	int width  = original->width();
	int height = original->height();
	cout << "Reached line 32" << endl;//added print statement
	// Create out.png
	PNG * output = setupOutput(width, height);//we need to give the output file the width and height from original. 
	//output = new PNG; //same as line 33
	//setupOutput(width, height);	
	
	// Loud our favorite color to color the outline
	RGBAPixel * myPixel = myFavoriteColor(192);
	cout << "Reached line 44" << endl;//added print statement
	// Go over the whole image, and if a pixel differs from that to its upper
	// left, color it my favorite color in the output
	for (int y = 1; y < height; y++) 
	{
		for (int x = 1;x < width; x++) 
		{
			// Calculate the pixel difference
			RGBAPixel * prev = (*original)(x-1, y-1);
			RGBAPixel * curr = (*original)(x  , y  );
			int diff = abs(curr->red   - prev->red  ) +
					   abs(curr->green - prev->green) +
					   abs(curr->blue  - prev->blue );

			// If the pixel is an edge pixel,
			// color the output pixel with my favorite color
			RGBAPixel * currOutPixel = (*output)(x,y);
			if (diff > 100)
				* currOutPixel = * myPixel; //we need to dereference!	
		}
	}
	cout << "Reached line 66" << endl;//added print statement	
	// Save the output file
	output->writeToFile("out.png");
	cout << "Reached line 71" << endl;//added print statement	
	// Clean up memory
	delete myPixel; 
	cout << "Reached line 74" << endl;//added print statement	
	delete output;
	cout << "Reached line 76" << endl;//added print statement	
	delete original;
	cout << "Reached line 78" << endl;//added print statement	
}
