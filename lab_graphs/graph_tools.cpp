/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

 using namespace std;

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph & graph, Vertex start, Vertex end)
{

	//algorithm from slides
    if(graph.getEdges().size()==0)//make sure its not empty duh
    {
    	return 0;
    }  
    int length = 0;//make a thing called length, initialize to zero
   	unordered_map<Vertex, Vertex> temp;//calling this thing a temp
    queue<Vertex> verticies;//create a queue of verticies
    
    graph.setVertexLabel(start, "VISITED");//set the vertex label
    verticies.push(start);//push on the start

    while(!verticies.empty())//until its empty
    {
    	//create a holder for the first thing in verticies queue
    	//this is pretty important
    	Vertex curr = verticies.front();
    	//now pop off
    	verticies.pop();
    	if(curr == end)//if were at the end
    	{
    		Vertex next = temp[curr];//make a new thing of type Vector and set it to
    		//curr of our unordered map above
    //setting the minpath (two cases)
    		while(next != start)
    		{
    			graph.setEdgeLabel(curr, next, "MINPATH");
    			length++;//increment length
    			curr = next;//move on to the next one
    			next = temp[curr];//set new next
    		}
    		//need to set edge label and increment length
    		graph.setEdgeLabel(curr, next, "MINPATH");
    		length++;//increment length
    		return length;
      	}
      	//important stuff here for visited
      	//make adjacent vector
      	vector<Vertex> adjacent = graph.getAdjacent(curr);
      	for(unsigned int long i = 0; i < adjacent.size() ; i++)//were checking every node
      	{
      		if(graph.getVertexLabel(adjacent[i]) != "VISITED")//if we haven't visited it
      		{
      			temp[adjacent[i]] = curr;//go to next
      			//set this thing to visited
      			graph.setVertexLabel(adjacent[i], "VISITED");
      			verticies.push(adjacent[i]);//throw that on our verticies queue!

      		}
      	}


    }
    return -1;//apparently we leave this?

}

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph & graph)
{

	//declaring some queues here
	//could be stacks but queues are more intuitive to me
	queue<Vertex> first;//holder 1 basically
	queue<Vertex> second;//holder 2 basically
	queue<Vertex> verticies;//same as in previous function
	queue<int> weight;//queue for holding the edge weights
    
    Vertex start = graph.getStartingVertex();//get a starting point
    verticies.push(start);//push it onto the verticies queue
    //mark the start point as visited (intuitive)
    //call the helper; not arguments are what I defined above

    find_minWeight_helper(graph, verticies, first, second, start, weight);

    int currMin = weight.front();//holder for the current min  weighted edge


}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort (http://www.cplusplus.com/reference/algorithm/sort/)
 *  instead of creating a priority queue.
 */


 void GraphTools::find_minWeight_helper(Graph & graph, queue<Vertex> & verticies , queue<Vertex> & first, queue<Vertex> second, Vertex &start, queue<int> &weight)
 {
 	return;
 }

void GraphTools::findMST(Graph & graph)
{
	DisjointSets mySet;//create a new disjoint set from the class from mp7.1
	int a;
	int b;
	int size = graph.getVertices().size();
	// lest give our set the appropriate size here
	mySet.addelements(size);//from dsets.cpp file
	vector <Edge> edges_holder = graph.getEdges();//fill up this vector with edges
	//using std::sort as described above
	sort(edges_holder.begin(), edges_holder.end());

	for(int i; i < edges_holder.size() ; i++)//loop though all of the edges here
	{
		a = mySet.find(edges_holder[i].dest);//using find from dsets.cpp
		b = mySet.find(edges_holder[i].source);//using find from dsets.cpp

		if(a != b)
		{
			//set MST if condidtion is met
			graph.setEdgeLabel(edges_holder[i].source, edges_holder[i].dest, "MST");
			mySet.setunion(a,b);//from dsets
		}

	}

	
}
