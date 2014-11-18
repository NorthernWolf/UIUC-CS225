/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <iostream>
 #include "math.h"

template<int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim> & first, const Point<Dim> & second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    //return false;

    if(first[curDim]==second[curDim])
    {
        return first < second;
    }
    else
    {
        return first[curDim] < second[curDim];
    }
    
}


template<int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim> & target, const Point<Dim> & currentBest, const Point<Dim> & potential) const
{
    /**
     * @todo Implement this function!
     */
    //return false;

     //first lets initialize stuff to hold the current and potential distance
     int currentDist = distance(currentBest, target);
     int potentialDist = distance(potential, target);

     //similar stucture as above
     if(currentDist==potentialDist)
     {
        return potential < currentBest;
     }
    
    
        return potentialDist < currentDist;
    
}




//need to build "distance" helper function used above
template<int Dim>
int KDTree<Dim>::distance(const Point<Dim> &first, const Point<Dim> &second) const
{
    int retVal = 0;//initialize a return value

    for(int i = 0; i<Dim; i++)
    {
        retVal += pow(first[i] - second[i], 2);// pow returns base raised to exponenent power
    }

    return retVal;//send back the retVal
}




template<int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > & newPoints)
{
    /**
     * @todo Implement this function!
     */

     points = newPoints;

     if(points.size() != 0)//if points isn't empty
     {
        //call the helper and build this thing!
        buildKDTree(0, 0, newPoints.size()-1);//dont forget -1 to account for zeroth term;
     }
}


template <int Dim>
void KDTree<Dim>::buildKDTree(int dimension, int bottom, int top)
{
    if(top == bottom)
    {
        return; //"base case"
    }

    int middle = (top+bottom)/2;//declare middle

    //call the "choose" helper function to sort of split this thing 
    choose(middle, bottom, top, dimension);

    if(bottom < middle) //check lower end
    {
        //make recursive call
        buildKDTree((dimension+1)%Dim, bottom, middle-1); //call this thing on the lower end
    }


    if(top > middle) //check upper end 
    {
        //make recursive call
        buildKDTree((dimension+1)%Dim, middle+1, top); //call this thing on the upper end
    }
    

}

//chose helper function
//basically quick selector 
template <int Dim>
void KDTree<Dim>::choose(int i, int bottom, int top, int curDim)
{
    while(bottom != top)
    {
        int holder = partition(bottom, top, i, curDim);//call partition function defined below
        if(holder == i)
        {
            return;//get out of here!
        }
        else if( i <holder)
        {
            top = holder-1; //set new bottom
        }
        else // if i > holder
        {
            bottom = holder+1;//set new top
        }
    }
}

template <int Dim>
int KDTree<Dim>::partition(int bottom, int top, int i, int curDim)
{
    Point<Dim> holder1 = points[i];
    //making a swap
    Point<Dim> holder2 = points[top];
    points[top] = points[i];
    points[i] = holder2;

    int holder3 = bottom;

    for(int j = bottom ; j < top ; j++)
    {
        if(smallerDimVal(points[i], holder1, curDim) || points[i] == holder1)
        {
            //another swap
            holder2 = points[holder3];
            points[holder3] = points[i];
            points[i] = holder2;
            holder3++;

        }
    }
    //swap again
    holder2 = points[top];
    points[top] = points[holder3];
    points[holder3] = holder2;
    return holder3;



}





template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> & query) const
{
    /**
     * @todo Implement this function!
     */
   //return Point<Dim>();


    //just return the call to its helper function
    Point<Dim> retVal =  NearestNeighbor_helper(0, query, 0, points.size()-1, points[(points.size()-1)/2]);
    return retVal;
}


template <int Dim>
Point<Dim> KDTree<Dim>::NearestNeighbor_helper(int curDim, const Point<Dim> &query, int bottom, int top, const Point<Dim> &currentBest) const
{
    Point<Dim> retVal = currentBest;//set a holder (call it return value) equal to currentBest to start
    bool target = true; //initialize our target bool to true

    if(bottom==top)
    {
        //this means were at a leaf
        //we need to check if were wcloser than current best and return the appropriate currnent best
        if(shouldReplace(query, currentBest, points[bottom]) == true)
        {
            retVal = points[bottom];//set the return value
            return retVal; //send that thing up!
        }
        retVal = currentBest; //otherwise return the currentBest
        return retVal;

    }


    //declare the middle point
    int middle = (bottom+top)/2;


    //now lets get to work on tricky stuff
    if(smallerDimVal(points[middle], query, curDim) && top > middle)
    {
        //recursive call to set retVal
        retVal = NearestNeighbor_helper((curDim+1)%Dim, query, middle+1, top, currentBest);
        target = false;
    }
    if (smallerDimVal(points[middle], query, curDim) && bottom <middle)
    {
        //recursive call to set retVal
        retVal = NearestNeighbor_helper((curDim+1)%Dim, query, bottom, middle-1, currentBest);
        target = true;
    }

    //look to see if the node were on is closer than what was obtained earlier
    if(shouldReplace(query, retVal, points[middle]))
    {
        retVal = points[middle];//set retVal appropriately
    }


    //lots of TA guidance here this is still a little foggy
    Point <Dim> holder = points[middle];
    if(pow(holder[curDim] - query[curDim], 2) <= distance(query, retVal))
    {
        if(target && top > middle)
        {   
            //recurisve call
            retVal = NearestNeighbor_helper((curDim+1)%Dim, query, middle+1, top, retVal);//same as above but replace currentBest with retVal!
        }
        if (target && bottom < middle)
        {
             retVal = NearestNeighbor_helper((curDim+1)%Dim, query, bottom, middle-1, retVal);//same as above but replace currentBest with retVal!
        }

    }

    //AND FINALLY
    return retVal;

}




