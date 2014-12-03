#ifndef DSETS_H
#define DSETS_H

#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//lets build this guy

class DisjointSets
{
	public: 


		//creates n unconnected root nodes at the end of the vector
		void addelements(int nums);

		//compress paths and work as described in lecture (optimizations?)
		int find(int elem);

		//union by size
		void setunion(int a, int b);


	private:
		//need to declare the vector of ints
		std::vector<int> s;//s for sets (from lecture)

		//isBigger helper
		//using root1 and root2 from lecture
		bool isBigger(int root1, int root2);

};

#endif //DSETS_H