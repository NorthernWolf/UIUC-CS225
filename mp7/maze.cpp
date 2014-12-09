#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <sys/time.h>
#include <time.h>
#include "maze.h"
#include "dsets.h"


//copied in includes from doxygen

using namespace std;

DisjointSet myMaze;//declaring a disjoint set so I can use find and setunion as directed by video to prevent it from cycling

//default constructor
SquareMaze::SquareMaze()
{

}


//makes a new square maze of the given height and width
void SquareMaze::makeMaze(int width, int height)
{
	return;
}


//uses representation of the maze to determine whether it is possible to travel in the given direction from the quare at coordinates (x,y)
bool SquareMaze::canTravel(int x, int y, int dir) const
{
	return false;
}

//sets whether or not the specified wall exists
void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
	//dir can be 0 (right) or 1(down)
	if(dir = 0)
	{

	}
	else
	{

	}
}

//solves the SquareMaze
vector<int> SquareMaze::solveMaze()
{

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