// **************************************************************
// *		   
// *  quadtree.h
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

class Quadtree
{
	public:
	
		//default contstuctor
		Quadtree();

		//constructor with parameters
		Quadtree( const PNG &source, int resolution);

		//copy constructor
		Quadtree(Quadtree const & other);

		//destructor
		~Quadtree();

		//assignment operator
		Quadtree const & operator=(Quadtree const & other);

		//deletes the current contents of this quadtree object, then turns it into a quadtree object representing the upper-left d by d block of source
		void buildTree(PNG const &source, int resolution);
		



		//gets the RGBAPixel corresponding to the pixel at the coordinates (x,y) in the bitmap image which the quadtree represents
		RGBAPixel getPixel(int x, int y) const;

		//returns the underlying PNG object represented by the quadtree
		PNG decompress() const;


		//reotates the quadtree objects underlying image clockwise by 90 degrees
		void clockwiseRotate();


		//compresses the image this quadtree represents
		void prune (int toleratnce);

		//this function is similar to prune, however, it does not actually prune the quadtree
		int pruneSize(int tolerance) const;

		//calculates and returns the minimum tolerance necessary to guarantee that upon pruning the tree, no more than numLeaves leaves remain in the quadtree
		int idealPrune(int numLeaves) const;

		void clear(); //clear helper

		

		void copy(Quadtree const &other); //clear helper



		//gets the RGBAPixel corresponding to the pixel at the coordinates (x,y) in the bitmap image which the quadtree represents
		RGBAPixel getPixel(int x_Value, int y_value, int resolution);

		//bool operator==(Quadtree const & other) const;
		

	
	
	private:

	// A simple class representing a single node of a Quadtree.
	// You may want to add to this class; in particular, it could probably
	// use a constructor or two...
	class QuadtreeNode
	{
		public:
			//this will need the big three
			//and its gonna need constructors

		
		
		
		QuadtreeNode();//default constructor

		QuadtreeNode const &operator=(QuadtreeNode const & other);//overload operator

		QuadtreeNode(RGBAPixel color);



		QuadtreeNode* nwChild;  // pointer to northwest child
		QuadtreeNode* neChild;  // pointer to northeast child
		QuadtreeNode* swChild;  // pointer to southwest child
		QuadtreeNode* seChild;  // pointer to southeast child

		RGBAPixel element;  // the pixel stored as this node's "data"
	};
	
	QuadtreeNode* root;    // pointer to root of quadtree
	
	//build tree helper
	void buildTree_helperFunction(QuadtreeNode* node, int levels, PNG const &source, int x, int y, int new_res);

	//helper for copy helper
	QuadtreeNode* copy_helper(QuadtreeNode* other);

	//helper for helper function
	void clear_helper_function(QuadtreeNode * &node);


	//decompress helper function
	PNG decompress_helper(QuadtreeNode* node, int levels, PNG const &source, int x, int y, int new_res);

	int res; //something to hold the resolution of the tree

	/**** Functions added for testing/grading                ****/
	/**** Do not remove this line or copy its contents here! ****/
	#include "quadtree_given.h"
};

#endif
