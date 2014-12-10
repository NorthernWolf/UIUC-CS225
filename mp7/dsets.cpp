#include "dsets.h"

using namespace std;


void DisjointSets::addelements(int num)
{
	//get the original size, calculate new size, resize s
/*

	//first lets get the original size
	unsigned long int orig_size = s.size();
	//calculate new size
	int new_size = num + orig_size;
	//resize s
	s.resize(new_size);

	//now lets do some adding
	while(orig_size < s.size())//until we get to the new size
	{
		s[orig_size] = -1;//were at a root if array value is -1
		orig_size++;//maybe orig_size isn't a good name for this..
		//eh 
	}
	*/
	//WAY simpler implemenetation
	//push back -1 on our vector s becasue roots are -1 and thats it
	for(int i =0; i<num;i++)
	{
		s.push_back(-1);
	}

}


//got this whole thing from disjoint sets lecture
int DisjointSets::find(int elem)
{
	int i = elem;//added this line
	
	//everything else from lecture slides

	if(s[i] <0)//root is -1
	{
		return i;
	}
	else
	{
		//recursive call
		return find(s[i]);	
	}
}

//also got this from disjoint sets lecture (mostly)
//uses isBigger helper function though so need to add that
void DisjointSets::setunion(int a, int b)
{

	//function parameters on lecture slides are root1 and root2
	//so we need to use the find function and set root1 and root2
	int root1 = find(a);
	int root2 = find(b);
	//and now the rest of the code is from the slides

	int newSize = s[root1] + s[root2];
	

	if(isBigger(root1,root2))//isBigger from slides
	{
		s[root2] = root1;
		s[root1] = newSize;
	}
	else
	{
		s[root1] = root2;
		s[root2] = newSize;
	}
}

//isBigger helper function
bool DisjointSets::isBigger(int root1, int root2)
{
	//pretty basic idea return true if s[root2] is bigger than s[root1]
	//if they're equal also return true
	if(s[root1] <= s[root2])
	{
		return true; 
	}
	else
	{
		return false;
	}


}