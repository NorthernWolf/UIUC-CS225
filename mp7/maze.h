#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "png.h"
//copied in includes from doxygen

using namespace std;


class SquareMaze
{
	public:

		SquareMaze();//default constructor


		//makes a new square maze of the given height and width
		void makeMaze(int width, int height);


		//uses representation of the maze to determine whether it is possible to travel in the given direction from the quare at coordinates (x,y)
		bool canTravel(int x, int y, int dir) const;

		//sets whether or not the specified wall exists
		void setWall(int x, int y, int dir, bool exists);

		//solves the SquareMaze
		vector<int> solveMaze();

		//draws the maze without solution
		PNG * drawMaze() const;

		//calls drawMaze() then solveMaze(); it modifies the PNG drom drawMaze to show the solution vector and the exit
		PNG * drawMazeWithSolution();

	private: 
		//include any private member functions like helper vectors
		//also helper functions for the other functions down here
		vector< vector< pair< int, int> > >mapGrid;//declare this private member function called mapGrid as a vector of vectors for setWall
		//used a pair in dictionary labs so we'll be able to use .first for x and .second for y

};


#endif // MAZE_H