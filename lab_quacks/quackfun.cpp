/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T QuackFun::sum(stack<T> & s)
{
    
    T temp; //my two local variables of type T
    T stackSum=0; //my two local variables of type T

    //base case first
    if(s.empty()){
        return T(); //base case
    }
    else{


        stackSum +=s.top();
        temp = s.top();
        s.pop();
        stackSum +=sum(s);
        

        s.push(temp);//restore temp

        return stackSum;


    }


}



   

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void QuackFun::scramble(queue<T> & q)
{
    stack<T> s;
    queue<T> q2; 
    int block = 1;

    //for even blocks load it into the stack and then pop it off the stack into the que (so they'll reverse)
    //for odd blocks, just load them into the que so they go in the right order
    //q2 is gonna hold the scrambled list

    if(q.empty()){
        return;
    }
    else if(!q.empty())
    {
        while(!q.empty())
        {


            if(block % 2 ==0)
            {
             //were on an even block so flip this thing
                //use stack to flip
                for(int j= 0;j<block;j++)
                {
                    if(!q.empty())
                    {
                    s.push(q.front());
                    q.pop();
                    }   
                }

                while(!s.empty())
                {
                    q2.push(s.top());
                    s.pop(); 
                }
            }
            else if (block%2==1)//odd block so don't flip 
            {
                

               
                //use que to not flip
                for(int k=0;k<block;k++)
                {

                    if(!q.empty())
                    {
                    q2.push(q.front());
                    q.pop();
                    }
                }
                

            }

        block++;
        }

    }
    
    //instead of using overload = operator just using this while loop and push and pop

    
    while(!q2.empty()){

        q.push(q2.front());
        q2.pop();
    
    }
}
    // Your code here


/**
 * @return true if the parameter stack and queue contain only elements of exactly
 *  the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in your return statement,
 *      and you may only declare TWO local variables of parametrized type T to use however you wish.
 *   No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be sure to comment your code VERY well.
 */
template <typename T>
bool QuackFun::verifySame(stack<T> & s, queue<T> & q)
{
    
    bool retval = true;
    /*
    T temp1;
    T temp2; 
    if(s.empty() || q.empty())
        return true;
    else
    {
    
    retval = verifySame(s,q);
    
    }
    */
    return retval;

}

