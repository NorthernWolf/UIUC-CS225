/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */
	 			
#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas * mapTiles(SourceImage const & theSource, vector<TileImage> const & theTiles)
{
    /**
     * @todo Implement this function!
     */

     MosaicCanvas * mosaic_ptr = new MosaicCanvas(theSource.getRows(), theSource.getColumns()); //declare new pointer

     vector<Point<3>> tree_vector;//get the vector to become the KDTree

     map<Point<3>, TileImage> tiles;//declare a new map


	for(auto& iterator : theTiles) //make an autofor loop to go though the theTiles Vector
	{

		//create a temporary RBBAPixel
		RGBAPixel temp = iterator.getAverageColor(); //used built in function get average color

		Point<3> holder; //declare a Point<3> holder
		holder[0] = temp.red; //0th element is red  
		holder[1] = temp.green; //1th element is green
		holder[2] = temp.blue; //2th element is blue

		tree_vector.push_back(holder);//then push the holder onto the tree vector thats going to become the KDTree!
		tiles[holder] = iterator;//set tiles at the key equal to the iterator
		//key is average color so you set that equal to the point so you can find what the tile is
	}


		KDTree<3> myTree = KDTree<3>(tree_vector);//construct a KDTree using tree_vector


		for (int i = 0; i < theSource.getRows(); i++) //go through every row 
		{
			for (int j = 0; j < theSource.getColumns(); j++) //go through every column
			{
				
				RGBAPixel temp2 = theSource.getRegionColor(i,j); //used built in function to get redion color

				Point<3> holder2; //declare a Point<3> holder2
				holder2[0] = temp2.red; //0th element is red  
				holder2[1] = temp2.green; //1th element is green
				holder2[2] = temp2.blue; //2th element is blue

				Point<3> holder3 = myTree.findNearestNeighbor(holder2);//used build in get nearest neightbor function. use holder 2 which we just populated above

				mosaic_ptr->setTile(i,j,tiles.at(holder3));//used build in setTile function ..third parameter uses holder3


			}
		}


		return mosaic_ptr;//return pointer the mosaic

	
}
