#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <sys/time.h>
#include <ostream>

#include <time.h>
#include "maze.h"
#include "dsets.h"


//copied in includes from doxygen

using namespace std;



//default constructor
SquareMaze::SquareMaze()
{
	//width and height = 0 for this thing
	currHeight = 0;
	currWidth = 0;
}
	//cout << "line 24" << endl;

//makes a new square maze of the given height and width
void SquareMaze::makeMaze(int width, int height)
{
	currHeight = height;
	currWidth = width;
	//maze.clear();


	//maze is disjoint set
	//grid is vector of pairs i.e. coordinates!!

	maze.addelements(width*height);//add elements to our disjoint set
	//width*height becasue we want one for each "coordinate" 
/*
	for (int i = 0; i < width*height; i++)
	{
		grid.push_back(0);//initialize this stuff to zero
	}
*/
	vector<cell> cell_coordinates;//make a vector of every coordinate
	//HINT: only care about bottom and right wall
	//bool rightWall;
	//bool bottomWall;
	//push this stuff back onto the cell coordinates vector
	for(int i = 0 ; i < currWidth-1; i++)
	{
		for(int j = 0; j < currHeight-1 ; j++)
		{

			cell walls;//create an object of type cell call it coords
			//wall walls;//create an object of type wall call it walls
			walls.x = i;
			walls.y = j;
			walls.rightWall = true;
			walls.bottomWall = false;
			if(i != currWidth-2)
			{
				cell_coordinates.push_back(walls);
			//cout<< line 64 << endl;
			}
			//otherwise not a right wall and then go to bottom
			walls.rightWall = false;
			walls.bottomWall = true;
			if(j != currHeight-2)
			{
				cell_coordinates.push_back(walls);
			}
			//cout<< "line 73" << endl;
		}
	}

	//now lets do some randomizing
	random_shuffle(cell_coordinates.begin(), cell_coordinates.end());//need to use iterator begin and end according to documentations
//cout<< "line 79" << endl;

	//now lets do some removing 
	//cell coordinates is the array of cell
	//cell are x,y coordinates
	while(!cell_coordinates.empty())
	{
		//check for cycles in deleting
		cell curr = cell_coordinates.back();


		cell_coordinates.pop_back();
//cout<< "line 91" << endl;

		if(curr.bottomWall)
		{
			if(maze.find((curr.y*currWidth)+curr.x) != maze.find(((curr.y+1)*width)+curr.x))
			{
				setWall(curr.x, curr.y, 1, false);
				maze.setunion((curr.y*currWidth)+curr.x , ((curr.y+1)*width)+curr.x);
			}	
		}
//cout<< "line 101" << endl;
		if(curr.rightWall)
		{
			//check with find
			if((maze.find(curr.y*currWidth)+curr.x) != maze.find((curr.y*width)+curr.x+1))
			{
				setWall(curr.x, curr.y, 0, false);
				maze.setunion((curr.y*currWidth)+curr.x , (curr.y*width)+curr.x+1 );
			}	
		}
		
	}

//cout<< "line 114" << endl;

}


//uses representation of the maze to determine whether it is possible to travel in the given direction from the quare at coordinates (x,y)
bool SquareMaze::canTravel(int x, int y, int dir) const
{
	if(x < 0 || y < 0 || currWidth  <= x || currHeight <= y) //check boundary conditions
	{
		return false;//out of bounds
	}

	int idx = (currWidth*y) + x;
	//4 cases 1,2,3,4
	switch(dir)
	{
		case 0: 
			return !deleted[idx].rightWall;
			break;
		case 1:
			return !deleted[idx].bottomWall;
			break;
		case 2:
			return !deleted[idx -1].rightWall;
			break;
		case 3:
			return !deleted[(currWidth*(y-1)) + x].bottomWall;
			break;
		default:
			return false;
	}
//cout<< "line 146" << endl;
}

//sets whether or not the specified wall exists
void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
	
	if(x < 0 || y < 0 || currWidth -1 <= x || currHeight-1 <= y) //check boundary conditions
	{
		return;//out of bounds
	}
	int idx = (currWidth*y) + x;
	//cout<< line 158<< endl;
	if(dir == 1)
	{
		deleted[idx].bottomWall = exists;
	}
//cout<< "line 163" << endl;

	//dir can be 0 (right) or 1(down)
	if(dir == 0)
	{
		//set that fucker to exists
		deleted[idx].rightWall = exists;
	}
	
}

//solves the SquareMaze
vector<int> SquareMaze::solveMaze()
{
	//this is what the doxygen says? LOL CANT FIGURE THIS OUT
	vector<int> directions;
	return directions;
}

//draws the maze without solution
PNG * SquareMaze::drawMaze() const
{

	PNG * output = new PNG();
	return output;
}

//calls drawMaze() then solveMaze(); it modifies the PNG drom drawMaze to show the solution vector and the exit
PNG * SquareMaze::drawMazeWithSolution()
{
	PNG * output = new PNG();
	return output;
}