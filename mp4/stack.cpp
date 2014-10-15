/**
 * @file stack.cpp
 * Implementation of the Stack class.
 *
 * @author CS 225 Course Staff
 * @date Fall 2009
 *
 * @author Chase Geigle
 * @date Fall 2012
 */
using namespace std; 
/**
 * Adds the parameter object to the top of the Stack. That is, the element
 * should go at the beginning of the list.
 *
 * @note This function must be O(1)!
 *
 * @param newItem The object to be added to the Stack.
 */
template<class T>
void Stack<T>::push(T const & newItem)
{
    if(myStack.size() != myStack.max_size())
    {
        myStack.push_front(newItem); //found push front on the website lel
    }
    //else
       // cout<< "The stack is full! Can't push!" <<endl;
        //return;
}   

/**
 * Removes the object on top of the Stack, and returns it. That is, remove
 * the element at the beginning of the list. You may assume this function
 * is only called when the Stack is not empty.
 *
 * @note This function must be O(1)!
 *
 * @return The element that used to be at the top of the Stack.
 */
template<class T>
T Stack<T>::pop()
{
    T holder;
    holder = myStack.front();//give a new node the value of the front of stack
    myStack.pop_front(); //delete the top of the stack
    return holder; 

    
}

/**
 * Adds an element to the ordering structure.
 *
 * @see OrderingStructure::add()
 */
template <class T>
void Stack<T>::add( const T & theItem ) {

    push(theItem);

}

/**
 * Removes an element from the ordering structure.
 *
 * @see OrderingStructure::remove()
 */
template <class T>
T Stack<T>::remove() {
    
    return pop();
}



/**
 * Finds the object on top of the Stack, and returns it to the caller.
 * Unlike pop(), this operation does not alter the Stack itself. It should
 * look at the beginning of the list. You may assume this function is only
 * called when the Stack is not empty.
 *
 * @note This function must be O(1)!
 *
 * @return The element at the top of the Stack.
 */
template<class T>
T Stack<T>::peek()
{
    return myStack.front();//return the front of the stack but don't delete it
}

/**
 * Determines if the Stack is empty.
 *
 * @note This function must be O(1)! Note that the std::list's size()
 *	function is O(n), so you should not attempt to use it here.
 *
 * @return Whether or not the stack is empty (bool).
 */

template<class T>
bool Stack<T>::isEmpty() const
{
    if(!myStack.empty())//if not empty return false
        return false;
    else if (myStack.empty())//if empty return true
        return true;
}
