//copied this stuff over from png.cpp
#include <cstdint>
#include <iostream>

#include "scene.h" //need to include header file
#include "image.h"//other header file

using std::uint8_t;
using namespace std;


//let's implement some functions!

Scene::Scene(int max)
{
	size_t i;
	MaxImages = max;
	
	xcoords = new int[max];
	ycoords = new int[max];
	images =new  Image *[max];//declare the array we want to make (type Image) of size max

	for(i=0;i<max;i++)
	{
		images[i] = NULL; //initialize everything in array to null
		xcoords[i] = 0; //inititalize to zero
		ycoords[i] = 0; //inititalize to zero
	}

	MaxImages = max;

}

Scene::~Scene()//destructor
{
	clear();
}

void Scene::clear()//clear function definition
{
	if (images!= NULL)//as long as images isn't null
	{
		for(size_t i = 0; i < MaxImages; i++)
		{
			delete images[i];//clear out array
		}
		delete [] images;	//delete actual array
	}
	if (xcoords!= NULL)
	{
		delete [] xcoords;
	}
	if (ycoords!= NULL)
	{
		delete [] ycoords;
	}
}

Scene::Scene(const Scene &source)
{
	copy(source);
}


void Scene::copy(const Scene &source)//copy function definition
{
//basically copied in code from Scene(int max) but using this new thing MaxImages for the size of the copy array


	MaxImages = source.MaxImages;//get size of MaxImage

	images = new Image * [MaxImages];//declare the array we want to make (type Image)
	xcoords = new int[MaxImages];
	ycoords = new int[MaxImages];
	for(size_t i=0;i<MaxImages;i++)
	{

		if(source.images[i] !=NULL)
		{
			images[i] = new Image(*(source.images[i])); //make the copies
		}
		else
		{
			images[i] = NULL;
		
		}
		xcoords[i] = source.xcoords[i];	//make the copies
		ycoords[i] = source.ycoords[i]; //make the copies						
	}
	
}

const Scene & Scene::operator = (const Scene &source)//copied this thing from room.cpp just made other source
{
	if (this != &source)
	{
		clear();
		copy(source);
	}
	return *this;


}

void Scene::changemaxlayers (int newmax)
{

	size_t i;
		
	if(newmax<MaxImages) //checking for invalid stuff
	{
		for(i = newmax;i<MaxImages; i++)
		{
			if(images[i] != NULL) //if there are non null pointers outrise the range
			{
				cout << "invalid newmax" << endl;//print out invalid
			}
		
		}
	}
	
	Image ** newImages = new Image *[newmax];//create new array
	int *newxcoords = new int [newmax];
	int *newycoords = new int [newmax];
	//lets build the new arrays
	for(i=0;i<newmax;i++)
	{
		if(i<MaxImages)
		{
			*newImages[i] = *images[i];
			newxcoords[i] = xcoords[i];		
			newycoords[i] = ycoords[i];	
		}
		else //if things don't go as planned, set everything to zero	
		{
			newImages[i] = NULL;
			newxcoords[i] = 0;	
			newycoords[i] = 0;
		}
	}
	//free stuff we used and then set the old arrays to the new arrays
	clear();
	images = newImages;
	xcoords = newxcoords;
	ycoords = newycoords;	


}


	

void Scene::addpicture (const char *FileName, int index, int x, int y)
{
	if(MaxImages <= index ||index <0)
	{
		cout << "index out of bounds" << endl; //for invalid conditions
	}
	else
	{
		Image *inputFile = new Image();
		inputFile->readFromFile(FileName);
		if(images[index] != NULL)
		{
			delete images[index];
		}
		
		images[index] = inputFile;
		xcoords[index] = x;
		ycoords[index] = y;
	}


}

void Scene::changelayer (int index, int newindex)
{
	if(newindex==index)
	{
		return;//do nothing
	}

	else if(MaxImages<=index || MaxImages<=newindex)//invalid condition
	{
		cout << "invalid index" << endl;//print out error statement
	}

	else
	{

		if(images[newindex] != NULL)
		{
			delete images[newindex];
		}
		images[newindex] = images[index];	
		images[index] = NULL; //delete the old one
		xcoords[newindex] = xcoords[index];//fill newindex with index
		ycoords[newindex] = ycoords[index];//fill newindex with index
		xcoords[index] = 0;//set old ones equal to zero 
		ycoords[index] = 0;//set old ones equal to zero
	}
}

void Scene::translate (int index, int xcoord, int ycoord)
{

	if(MaxImages<=index || MaxImages == NULL || index <0)//invalid condition
	{
		cout << "invalid index" << endl;//print out error statement
	}
	else
	{
			xcoords[index] = xcoord; //change the coordinates
			ycoords[index] = ycoord; //change the coordinates
	}


}

void Scene::deletepicture(int index)
{
	if(MaxImages<=index || MaxImages == NULL || index <0)//invalid condition
	{
		cout << "invalid index" << endl;//print out error statement
	}
	else 
		delete images[index];//free the space
		images[index] = NULL;//set to null
		xcoords[index] = 0;//set the coordinates to zero
		ycoords[index] = 0;//set the coordinates to zero




}

Image * Scene::getpicture (int index) const
{
	if(MaxImages<= index || index<0) //check if its invalid
	{
		cout << "invalid index" << endl;

	}
	else
	{
		return images[index];//return the index
	}

}




Image Scene::drawscene() const //here goes the big one
{
//according to the tip, determine min width and height first
	size_t minWidth =0;//define the min width
	size_t minHeight =0; //define the min height	
	for(size_t k = 0; k<MaxImages;k++)
	{
		if(images[k]!= NULL)
		{
			if(minWidth <(images[k]->width() + xcoords[k]))//if its the corner spot
			{
				minWidth = images[k]->width() + xcoords[k];//set min width equal to that spot
			}
			if(minHeight <(images[k]->height() + ycoords[k]))//if its the corner spot
			{
				minHeight = images[k]->height() + ycoords[k];//set min height equal to that spot
			}
		//k and l are awkward index names but I wanted to reserve i and j for the indexes of the 
		//double for loop when it goes through each pixel
		}
	}	
	//create a new Image object
	Image myImage;
	//give it the approptiate min coordinates
	myImage.resize(minWidth, minHeight);

	//now we need to set this myImage's coordinates
	for(size_t l = 0; l<MaxImages; l++)
	{
		if(images[l]!= NULL)//as longs as its not null
		{
			//loop through all the x and y pixels (double for loop)
			for(size_t i = 0; i<images[l]-> width();i++)
			{
				for(size_t j = 0; j<images[l] -> height(); j++)
				{

					//finally, the actual assignment statement
					*myImage(xcoords[l]+i, ycoords[l]+j) = *(*images[l])(i,j);
					
				}
			}

		}
	}
	return myImage;
}



