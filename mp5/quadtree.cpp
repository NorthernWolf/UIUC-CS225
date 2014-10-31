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
	res = 0;

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
	res = 0;
	//default constructor
	//nothing goes here
}

Quadtree::Quadtree(const PNG &source, int resolution)
{
	root = NULL;
	buildTree(source, resolution);//define new root node accoring to constructor I built
}

Quadtree::Quadtree(Quadtree const &other)
{
	if(other.root == NULL){
		root = NULL;
		return;
	}
	copy(other);
	res = other.res;
}


void Quadtree::copy(Quadtree const &other)
{
	copy_helper(root, other.root);
	res = other.res;
}

Quadtree::QuadtreeNode* Quadtree::copy_helper(QuadtreeNode* &thisNode, QuadtreeNode* other)
{
	if (other == NULL)
        return NULL;

    // Copy this node and it's children    
    thisNode = new QuadtreeNode(other->element);
    thisNode->swChild  = copy_helper(thisNode->swChild, other->swChild);
    thisNode->seChild = copy_helper(thisNode->seChild, other->seChild);
    thisNode->nwChild  = copy_helper(thisNode->nwChild, other->nwChild );
    thisNode->neChild = copy_helper(thisNode->neChild, other->neChild);

    return thisNode;
}

Quadtree const & Quadtree::operator=(Quadtree const &other)
{
	if(this != &other){
		clear();
		copy(other);
	}
	return *this;//now return yourself
}

void Quadtree::buildTree(PNG const &source, int  resolution)
{
	root = new QuadtreeNode();//create the root node
	res = resolution;
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
	
	return getPixel_helper(root, x, y, res);

}


RGBAPixel Quadtree::getPixel_helper(QuadtreeNode *node, int x, int y, int resolution) const
{
	if(root==NULL)
		return RGBAPixel();//if its an empty tree, return default RBGAPixel constructor


	
		//check quadrant

		if(x< resolution/2 && y <resolution/2 && node->nwChild != NULL) //has one or all 4 children so check one NW
		{
			return getPixel_helper(node->nwChild, x,  y, resolution/2);
		}

		else if(x>=resolution/2 && y >= resolution/2 && node->nwChild != NULL)//SE
		{
			return getPixel_helper(node->seChild, x-(resolution/2),  y-(resolution/2), resolution/2);
		}

		else if(x<resolution/2 && y>= resolution/2 && node->nwChild != NULL) //SW
		{
			return getPixel_helper(node->swChild, x,  y-(resolution/2), resolution/2);
		}

		else if (x>=resolution/2 && y< resolution/2 && node->nwChild != NULL) //NE
		{
			return getPixel_helper(node->neChild, x-(resolution/2),  y, resolution/2);
		}

		else
			return node->element;//were where we cant to be! return the element

		
}



PNG Quadtree::decompress() const
{
	if(root == NULL) //if tree is empty, return default PNG()
	{
		return PNG();
	}

	PNG source = PNG(res, res); //create a new PNG
		//res = resolution;
	//PNG(res, res)
	//int levels = log2(resolution); //level is log base 2 of the resolution they give us
	//return decompress_helper(root, levels, source, 0,0, resolution);//?
	//decompress function
	decompress_helper(root, source, 0,0, res);
	return source;
}


void Quadtree::decompress_helper(QuadtreeNode* node, PNG &source, int x, int y, int new_res) const
{

	if(node == NULL) //if tree is empty, return default PNG()
	{
		return;
	}



	//Like build tree but opposite? ... maybe recurse all the way down to the bottom and return the color at each level
	//or return the color at the leaf level?
	


	if(node->nwChild == NULL){// quadtree has zero children or all 4 so only need to check one
		//were at a leafe lets populate this things node
		for(int i = x ; i<x+new_res; i++){
			for(int j = y; j<y+new_res; j++){
				*(source(i,j)) = node->element;
			}
		}
		
	}
	
	
	//now make recursive call, go all the way to the bottom

	decompress_helper(node->nwChild, source, x , y , new_res/2 );

	decompress_helper(node->neChild, source, x+(new_res/2) , y , new_res/2 );

	decompress_helper(node->swChild, source, x , y +(new_res/2), new_res/2 );

	decompress_helper(node->seChild, source, x +(new_res/2) , y +(new_res/2), new_res/2 );

}



void Quadtree::clockwiseRotate()
{
	helper_clockwiseRotate(root);
}

void Quadtree::helper_clockwiseRotate(QuadtreeNode * node)
{

	if(node == NULL) return;

//recurse all the way down

	helper_clockwiseRotate(node->nwChild);
	helper_clockwiseRotate(node->neChild);
	helper_clockwiseRotate(node->swChild);
	helper_clockwiseRotate(node->seChild);

	//and now we just make a swap
	QuadtreeNode * nwHolder = node->nwChild;
	QuadtreeNode * neHolder = node->neChild;
	QuadtreeNode * swHolder = node->swChild;
	QuadtreeNode * seHolder = node->seChild;


	//make rotation
	node->nwChild = swHolder;
	node->neChild = nwHolder;
	node->seChild = neHolder;
	node->swChild = seHolder;



}


//compresses the image this quadtree represents
void Quadtree::prune (int toleratnce)
{
	return;
	//prune_helper(tolerance, root);
}

void Quadtree::prune_helper(int tolerance, QuadtreeNode * node)
{
	/*
	recurse_to_bottom(node, node);

	if(tolerance < allowable)
	{
		
	}
	*/
}
int Quadtree::allowable_calculation(QuadtreeNode * node1, QuadtreeNode * node2)
{
		int r1 = node1->element.red;
		int g1 = node1->element.green;
		int b1 = node1->element.blue;

		int r2 = node2->element.red;
		int g2 = node2->element.green;
		int b2 = node2->element.blue;;

		int allowable = (r2-r1)*(r2-r1) + (g2-g1)*(g2-g1) + (b2-b1)*(b2-b1);

		return allowable; 

}

int Quadtree::recurse_to_bottom(QuadtreeNode* origNode, QuadtreeNode * node)
{	
/*
	if (node->nwChild == NULL){
		//allowable_calculation(origNode, node);
		return allowable_calculation(origNode, node);
	}

	recurse_to_bottom(origNode, node->nwChild);
	recurse_to_bottom(origNode, node->neChild);
	recurse_to_bottom(origNode, node->swChild);
	recurse_to_bottom(origNode, node->seChild);

*/
	return 0;
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

