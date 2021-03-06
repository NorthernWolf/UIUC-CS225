/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */

#include <iostream>

using namespace std;

template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1
    clear();//call the clear function
}
/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    
    //make a while loop and go through every part of the linked list
    //then set head and tail = NULL
    ListNode * t;//making temp pointer T like in tutorial
    
    while(head != NULL) //until head is not zero
    {
        t = head -> next; //set T equal to the link of head
        delete head;//delete the head
        head = t;//set new head
    }
        head = NULL;// set head and tail pointers NULL since linked list is gone
        tail = NULL;
        length = 0;//also length of list is now zero
        t = NULL;//set temp pointer equal to null (point to garbage)
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata)
{
    
    ListNode * newHead = new ListNode(ndata);//make a new node to add to the front and give it ndata

    if(head != NULL)//when list isn't empty
    {
    //using head and data as defined in list.h
    //set the link of the new node we created equal to ndata
    // (ndata is function argument and thing were adding)
    newHead->next = head;//set the pointer of new node to original head
    newHead->prev = NULL;//set the previous pointer to NULL
    head = newHead;//set the new head of the linked list to the newHead node
    }
    else if (head == NULL || tail == NULL)//list is empty
    {
        head = newHead;//new node is the head
        tail = newHead;//new node is the tail
        head->prev = NULL;//points to null
        head->next = NULL;//points to null
        tail->next = head->next;//there's one node
        tail->prev = head->prev;//so the head and tail prev and next pointers are the same. i.e. NULL
    }
   
    length = length+1;//increment length
    newHead = NULL; //free the memory!


}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack( const T & ndata )
{
    ListNode * newTail = new ListNode(ndata);//make our new node and give it data ndata

    if(head != NULL)
    {    
    newTail->next = NULL;//set its next pointer to null
    tail->next = newTail;//set old tail pointer to newTail
    newTail->prev = tail;//set the back pointer of new tail to point to tail
    tail = newTail;//newTail is now tail
    }
    else if (head == NULL || tail == NULL)
    {
        head = newTail;//new node is the head
        tail = newTail;//new node is the tail
        head->prev = NULL;//points to null
        head->next = NULL;//points to null
        tail->next = head->next;//there's one node
        tail->prev = head->prev;//so the head and tail prev and next pointers are the same. i.e. NULL
    }

    length = length +1;//incrememnt the length
    newTail = NULL; //free the memory
    
}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse( ListNode * & startPoint, ListNode * & endPoint )
{
  


    if(startPoint ==NULL || endPoint== NULL)
        return;

    ListNode * currentThing = startPoint;//define a pointer to point to stuff
    ListNode * whereToStop = endPoint->next;
    //ListNode * origEndPointNext = endPoint->next;
    //ListNode * origStartPointPrev = startPoint->prev;

    while(currentThing != whereToStop)
    {

        //just doing a basic swap here
        //made a temporary thing called holder for the swap
        //then swapped currentThing->prev and currentThing->next
        ListNode * holder = currentThing->next;
        //cout<<endPoint<<endl;
        currentThing->next = currentThing->prev;
        currentThing->prev = holder;
        //traverse list
        currentThing = currentThing->prev;
    }  

    //update new start and end points
    //using a swap again
    ListNode * otherHolder = startPoint;
    startPoint = endPoint;
    endPoint = otherHolder;

    //special case conditions... causing the program to have some issues

  
    
    ListNode *holder1 = startPoint->prev;
    startPoint->prev = endPoint->next;
    endPoint->next = holder1; 
    
  
}


/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth( int n )
{

    if (n == 0 ){
       return;//do nothing.. there's nothing to do
    }
    
    else if(length == 1 )//if list is only 1 node
    {
        return;//same as previous there's nothing to do
    }
    else if(head==NULL || tail==NULL)//length = 0
    {
        return;//do nothing.. empty list
    }
    else if (n >= length)
    {
        reverse(head, tail);//if n is large enough, just reverse the list
        return;
    }
   
    else //normal scenario. I.E. if 2 <= n <length
    {
      
        ListNode * newStartPoint = head;//new start point will always be at head
        ListNode * newendPoint= NULL;
        ListNode * traversePointer = head; //start our traverse pointer at the head
        ListNode * newHead = NULL; 
       

      
        //ListNode * endnext = head;
        while(traversePointer!= NULL)//keep going until out traverse pointer hits the end
        {
            
                
    

            for(int i=1 ; i<n ; i++) //keep traversing until nth element
            {
                
                   if(traversePointer->next!= NULL)
                   {
                    //traverse list until we get to nth element
                    traversePointer = traversePointer->next;//traverse list until we get to nth element 
                    //cout<<"inside for loop"<<endl;
                    }
            
            }
            
            
            
            reverse(newStartPoint, traversePointer);//call the actual reverse function
           
            newStartPoint = traversePointer->next;//next chunk starts at transverse pointer next
            traversePointer = traversePointer->next;//move transverse pointer along
            newendPoint = traversePointer;//new endpoint is gonna be where transverse pointer stops
             //the new tail is gonna hold the value of transverse pointer
            //still need to set the new head?
           

        }  
        tail = newendPoint;     
    }
}


/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    /// @todo Graded in MP3.1

    int nodeNumber = 1; //make something to keep track of which node were on


    ListNode * mypointer = head;
    ListNode * holder = NULL;
   

    if(head==NULL || tail== NULL)
        return;
    else if (length == 1 || length == 0)
        return;
    else
        while(mypointer->next != NULL)
        {
            if(nodeNumber%2==1) //odd numbered list node don't do anything
            {
                nodeNumber++; //increase node number
                mypointer = mypointer->next; //move pointer along
            }
            else if(nodeNumber%2 == 0)//now we need to take out the node and append it to the back
            {

                holder = mypointer->next; //point holder to next node we want to check
                mypointer->next->prev = mypointer->prev;//put the prev pointer of next node equal to earlier node
                mypointer->prev->next = mypointer->next;//put the next pointer of earlier node equal to the next node
                mypointer->prev = tail;//move pointer so its prev is tail
                mypointer->next = NULL;//set the next null
                tail->next = mypointer;//make original tail next point to thing were appending at end
                //now update tail
                tail = mypointer;

                mypointer = holder;//move pointer to next thing
                nodeNumber++;//increment node number

            }
                 
            
        }







}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode * secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head)
    {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    }
    else
    {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL)
    {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint)
{
    /// @todo Graded in MP3.2
    //return NULL; // change me!


    ListNode *myPointer = start;
    
    for(int i=0 ; i< splitPoint; i++)
    {
        myPointer = myPointer->next;//traverse until we get to splitpoint

    }
   
        myPointer->prev->next = NULL;//set the next pointer of the previous thing to NULL
        myPointer->prev = NULL; //make the previous pointer of myPointer point to nothing
        return myPointer;//return the second list created from the split.. my pointer is the head of the second list




}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T> & otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if(tail != NULL)
    {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode * second)
{
    /// @todo Graded in MP3.2
    //return NULL; // change me!


    ListNode * list1 = first;
    ListNode * list2 = second;
    ListNode * sortedList = NULL;
    ListNode * minHolder = NULL;

        //check if lists are empty????
        if(list1 == NULL)
            return list2;
        else if(list2==NULL)
            return list1;

        //compare the values and then increment the pointers
        if(list2->data < list1->data)
        {
            minHolder = list2;//set min holder to smallest data
            list2 = list2->next; //increment pointer

        }
        else //if(list1->data < list2->data)
        {
            minHolder = list1;//set min holder to smallest data
            list1 = list1->next; //increment pointer
            
        }
 /*       else if(list1->data == list2->data)
        {
            //if they're equal basically don't do anything just move to next elements of list
            list1 = list1->next; //increment pointer
            list2 = list2->next; //increment pointer
        }
*/

        //this will find the min value of the two lists
        //set sortedList =  minHolder; so that the first node is the smallest element
        sortedList = minHolder;
        //now lets get to work checking the rest!
    while(list1 != NULL && list2 !=NULL)
    {
        if(list1->data < list2->data)
        {
            minHolder->next = list1;//set next thing in list to be the next smallest element
            list1 = list1->next; //increment pointer
        }
        else //if(list2->data < list1->data)
        {
            minHolder->next =list2;//set next thing in list to be the next smallest element
            list2 = list2->next; //increment pointer

        }
        minHolder = minHolder->next;//increment minholder
    }
    if(list1 != NULL)
    {
        minHolder->next = list1;
    }
    if(list2 != NULL)
    {
        minHolder->next = list2;
    }



    return sortedList;//returns the sorted list


}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode * List<T>::mergesort(ListNode * start, int chainLength)
{
   /// @todo Graded in MP3.2
    //return NULL; // change me!

   //base case: length = 1
    if(chainLength ==1)
    {
        return start;
    }
    else
    {
        //we need lengths to be able call mergesort on our list
        int midpoint = chainLength/2;//find the midpoint

        int list1Length = chainLength-midpoint;//set the length of list 1 
        int list2Length = chainLength - list1Length;//set the lengh of list 2 accordingly
       



    //start point of list 1 is 'start'
    //start point of list 2 is here
    //ListNode * list2Start= split(start, midpoint);

    ListNode * list1 = mergesort(start, list1Length);
    ListNode *list2 = mergesort(split(start, midpoint), list2Length);

    

    return merge(list1, list2); //return the two lists merged
    }
}
