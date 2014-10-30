// **************************************************************
// *		   
// *  quadtree.cpp
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#include "quadtree.h"
#include <math.h>  

using namespace std;

/*for 5.1 implement:

 big 3: destructor, copy constructor, assignment overload operator
 constructor(s)
 buildTree
 getPixel
 decompress
 */

Quadtree::QuadtreeNode::QuadtreeNode()
{
	nwChild = NULL;
	neChild = NULL;
	swChild = NULL;
	seChild = NULL;

	element = RGBAPixel();
}


//quadtreeNODE constructor
Quadtree::QuadtreeNode::QuadtreeNode(RGBAPixel color)
{
	nwChild = NULL;
	neChild = NULL;
	swChild = NULL;
	seChild = NULL;

	element = color;
}


Quadtree::~Quadtree() //destructor
{
	clear();
}

void Quadtree::clear() //helper clear function ... definitely need to check this one!
{
	clear_helper_function(root);


}

void Quadtree::clear_helper_function(QuadtreeNode * & node)
{

	if(node==NULL)//base case
	{
		return;//go back up one node 
		//returning from a recursive call takes you up one level (Whoever called it!)

	}

	//recurse all the way down
	clear_helper_function(node->nwChild);
	clear_helper_function(node->neChild);
	clear_helper_function(node->swChild);
	clear_helper_function(node->seChild);

	//after base case checks if were at a leaf, delete that thing
	delete node;
	node= NULL;
}

Quadtree::Quadtree()
{
	root = NULL;
	//default constructor
	//nothing goes here
}

Quadtree::Quadtree(const PNG &source, int resolution)
{
	
	buildTree(source, resolution);//define new root node accoring to constructor I built
}

Quadtree::Quadtree(Quadtree const &other)
{
	copy(other);
	
}


void Quadtree::copy(Quadtree const &other)
{
	copy_helper(other.root);
}

Quadtree::QuadtreeNode* Quadtree::copy_helper(QuadtreeNode* other)
{
	if (other == NULL)
        return NULL;

    // Copy this node and it's children    
    QuadtreeNode * newNode = new QuadtreeNode(other->element);
    newNode->swChild  = copy_helper(other->swChild);
    newNode->seChild = copy_helper(other->seChild);
    newNode->nwChild  = copy_helper(other->nwChild );
    newNode->neChild = copy_helper(other->neChild);

    return newNode;
}

Quadtree const & Quadtree::operator=(Quadtree const &other)
{

	clear_helper_function(root);//clear yourself
	copy(other);//copy other's stuff into you
	return *this;//now return yourself

}

void Quadtree::buildTree(PNG const &source, int  resolution)
{
	root = new QuadtreeNode();//create the root node

	int levels = log2(resolution); //level is log base 2 of the resolution they give us
	buildTree_helperFunction(root, levels, source, 0, 0, resolution);
	//levels is number of times we want to recurse down
	//x,y is minimumm point
	//new res is the new resolutions we have on the subtree now
}

void Quadtree::buildTree_helperFunction(QuadtreeNode* node, int levels, PNG const &source, int x, int y, int new_res)
{
	//node->sw, se, ne, nw = new Node
	//call helper on each children
	//stop at level=0
	if(levels==0){
		node->element = *(source(x,y));
		//make the element (the date of node) equal to operator(x,y) on source
		return;
	}
	
	//create new nodes for the chilren
	node->nwChild = new QuadtreeNode();
	node->neChild = new QuadtreeNode();
	node->swChild = new QuadtreeNode();
	node->seChild = new QuadtreeNode();

	//now make recursive call, change min coordinates appropriately
	buildTree_helperFunction(node->nwChild, levels-1, source, x , y , new_res/2 );

	buildTree_helperFunction(node->neChild, levels-1, source, x+(new_res/2) , y , new_res/2 );

	buildTree_helperFunction(node->swChild, levels-1, source, x , y +(new_res/2), new_res/2 );

	buildTree_helperFunction(node->seChild, levels-1, source, x +(new_res/2) , y +(new_res/2), new_res/2 );


	//now set averages for internal nodes

	int nwred = (node->nwChild)->element.red;
	int nered = (node->neChild)->element.red;
	int swred = (node->swChild)->element.red;
	int sered = (node->seChild)->element.red;
	int aveRed = (nwred+nered+swred+sered)/4;

	int nwgreen = (node->nwChild)->element.green;
	int negreen = (node->neChild)->element.green;
	int swgreen = (node->swChild)->element.green;
	int segreen = (node->seChild)->element.green;
	int aveGreen = (nwgreen+negreen+swgreen+segreen)/4;

	int nwblue = (node->nwChild)->element.blue;
	int neblue = (node->neChild)->element.blue;
	int swblue = (node->swChild)->element.blue;
	int seblue = (node->seChild)->element.blue;
	int aveBlue = (nwblue+neblue+swblue+seblue)/4;

	node->element.red = aveRed;
	node->element.green = aveGreen;
	node->element.blue = aveBlue;

	//wow


}

RGBAPixel Quadtree::getPixel(int x, int y) const
{
	//get pixel function
	return RGBAPixel();


	//This functions returns an RGBAPixel from png.cpp
	/*
	RGBAPixel & PNG::_pixel(size_t x, size_t y) const
	{
	return _pixels[_width * y + x];
	}

*/
}

PNG Quadtree::decompress() const
{
	//res = resolution;
	//PNG(res, res)
	//int levels = log2(resolution); //level is log base 2 of the resolution they give us
	//return decompress_helper(root, levels, source, 0,0, resolution);//?
	//decompress function
	return PNG();
}


PNG Quadtree::decompress_helper(QuadtreeNode* node, int levels, PNG const &source, int x, int y, int resolution)
{
/*
	if(root == NULL) //if tree is empty, return default PNG()
	{
		return PNG();
	}
	//Like build tree but opposite? ... maybe recurse all the way down to the bottom and return the color at each level
	//or return the color at the leaf level?
	if(levels==0){
		node->element = *(source(x,y));//why source here? .. but how else?
		//make the element (the date of node) equal to operator(x,y) on source
		return node->element;
	}
*/	
	/*
	I don't think I need to make new quadtree nodes here.. but how do I call the childrn in the decompress helper?
	node->nwChild = new QuadtreeNode();
	node->neChild = new QuadtreeNode();
	node->swChild = new QuadtreeNode();
	node->seChild = new QuadtreeNode();
	*/
	//now make recursive call, change min coordinates appropriately
/*
	decompress_helper(node->nwChild, levels-1, source, x , y , new_res/2 );

	decompress_helper(node->neChild, levels-1, source, x+(new_res/2) , y , new_res/2 );

	decompress_helper(node->swChild, levels-1, source, x , y +(new_res/2), new_res/2 );

	decompress_helper(node->seChild, levels-1, source, x +(new_res/2) , y +(new_res/2), new_res/2 );

*/

	return PNG();
	
}



void Quadtree::clockwiseRotate()
{
	return;
}

//compresses the image this quadtree represents
void Quadtree::prune (int toleratnce)
{
	return;
}

//this function is similar to prune, however, it does not actually prune the quadtree
int Quadtree::pruneSize(int tolerance) const
{
	return 0;
}

//calculates and returns the minimum tolerance necessary to guarantee that upon pruning the tree, no more than numLeaves leaves remain in the quadtree
int Quadtree::idealPrune(int numLeaves) const
{
	return 0;
}

