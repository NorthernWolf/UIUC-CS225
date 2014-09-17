#ifndef SCENE_H
#define SCENE_H

//copied all this over from png.h
//changed a few things

// c-style includes
#include <stdio.h>
#include <stdlib.h>

// c++ style includes
#include <string>
#include <iostream>
#include <sstream>

// local includes
#include "image.h"
#include "png.h"

using std::cerr;
using std::endl;
using std::string;
using std::stringstream;

//making the image subclass of PNG
class Scene
{
	public:
		//lets add some member functions
		Scene(int max);//initialize scene object to be able to hold max number of images (indices 0 to max-1)

		~Scene();//destructor

		Scene(const Scene &source);//copy constructor to make independent copy

		const Scene & operator = (const Scene &source);//assignment operator for scene class

		void changemaxlayers (int newmax); //Modifies the size of the array of Image pointers without changing their indices

		void addpicture (const char *FileName, int index, int x, int y);//comments below
		//This function will add a picture to the scene, by placing it in the array cell corresponding to the given index, and 			//storing its x coordinate and y coordinate.
		
		void changelayer (int index, int newindex);//Moves an Image from one layer to another

		void translate (int index, int xcoord, int ycoord);//Changes the x and y coordinates of the Image in the specified layer

		void deletepicture (int index);//Deletes the Image at the given index

		Image * getpicture (int index) const;//This function will return a pointer to the Image at the specified index, 
											//not a copy of it

		Image drawscene () const;//Draws the whole scene on one Image and returns that Image by value

	private:

		void clear();//clear function
		Image ** images;//array pointer
		void copy(const Scene &source);//copied this thing from room.h from lab_memory
		int MaxImages;//making variable for copy 
		int * xcoords;//make pointer type for xcoords
		int * ycoords;//make pointer type for ycoords
		

};

#endif
