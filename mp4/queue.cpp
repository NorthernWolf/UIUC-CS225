/**
 * @file queue.cpp
 * Implementation of the Queue class.
 *
 * @author CS 225 course staff
 * @date Fall 2009
 */

/**
 * Adds the parameter object to the back of the Queue.
 *
 * @param newItem object to be added to the Queue.
 */
template<class T>
void Queue<T>::enqueue(T const & newItem)
{
    inStack.push(newItem); 
}

/**
 * Removes the object at the front of the Queue, and returns it to the
 * caller.
 *
 * @return The item that used to be at the front of the Queue.
 */
template<class T>
T Queue<T>::dequeue()
{
    if(outStack.isEmpty())
    {
        while(!inStack.isEmpty())//until the inStack empties out

            outStack.push(inStack.pop()); //pop stuff off of instack and push it onto outstack
    }

    return outStack.pop(); //"pop" off the "first" value of oustack
}

/**
 * Adds an element to the ordering structure.
 *
 * @see OrderingStructure::add()
 */
template <class T>
void Queue<T>::add( const T & theItem ) {


    enqueue(theItem);
}

/**
 * Removes an element from the ordering structure.
 *
 * @see OrderingStructure::remove()
 */
template <class T>
T Queue<T>::remove() {
    
    return dequeue();
}

/**
 * Finds the object at the front of the Queue, and returns it to the
 * caller. Unlike pop(), this operation does not alter the queue.
 *
 * @return The item at the front of the queue.
 */
template<class T>
T Queue<T>::peek()
{
    //flip instack into outstack
    //peek the bottom element of instack which is the top element of outstack yaaayyyyy
    if(outStack.isEmpty())
    {
        while(!inStack.isEmpty())//until the inStack empties out

            outStack.push(inStack.pop()); //pop stuff off of instack and push it onto outstack
    }

    return outStack.peek();//peek at top of outstack
}

/**
 * Determines if the Queue is empty.
 *
 * @return bool which is true if the Queue is empty, false otherwise.
 */
template<class T>
bool Queue<T>::isEmpty() const
{
        //both instack and outstack should be empty for isEmpty to return true
        return inStack.isEmpty() && outStack.isEmpty(); //will return true if both are empty! if either are false it'll return false
}
