/**
 * @file list.cpp
 * Singly Linked List (lab_gdb).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 *
 * @author Veer Dedhia
 * @date (modified) Spring 2014
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    // @todo Graded in lab_gdb
    // Write this function based on mp3
   //make a while loop and go through every part of the linked list
    //then set head and tail = NULL
   ListNode * t;
    
    while(head != NULL) //until head is not zero
    {
        t = head -> next; //set T equal to the link of head
        delete head;//delete the head
        head = t;//set new head
    }
        head = NULL;// set head and tail pointers NULL since linked list is gone
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
    // @todo Graded in lab_gdb
    // Write this function based on mp3
    ListNode * newHead = new ListNode(ndata);//make a new node to add to the front and give it ndata

    if(head != NULL)//when list isn't empty
    {
    //using head and data as defined in list.h
    //set the link of the new node we created equal to ndata
    // (ndata is function argument and thing were adding)
    newHead->next = head;//set the pointer of new node to original head
    head = newHead;//set the new head of the linked list to the newHead node
    }
    else if (head == NULL)//list is empty
    {
        head = newHead;//new node is the head
       
        head->next = NULL;//points to null
        
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
    // @todo Graded in lab_gdb
    // NOTE: Do not use this implementation for MP3!
    ListNode * temp = head;

    if(temp == NULL)
    {
        head = new ListNode(ndata);
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new ListNode(ndata);//changed temp to temp->next
       
    }
     length++;
}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    head = reverse(head, NULL, length);
}

/**
 * Helper function to recursively reverse the enitre sequence of
 * linked memory inside a List.
 *
 * @param curr The current node we are reversing
 * @param prev The node that should be placed before the current node in the
 * final reversed list
 * @param len The length of the remaining list to be reversed
 */
template <class T>
typename List<T>::ListNode* List<T>::reverse( ListNode * curr, ListNode * prev, int len )
{
    // @todo Graded in lab_gdb
    ListNode * temp;
    if (len == 1)//only change
    {
        curr->next = prev;
        return curr;
    }
    else
    {
        temp = reverse(curr->next, curr, len-1);
        curr->next = prev;
        return temp;
    }
}

/**
 * Shuffles the current list by applying a perfect shuffle once. This entails
 * splitting the list in half, then interleaving the two halves.
 * For example:
 * start : < 1, 2, 3, 4, 5 >
 * split : < 1, 2, 3 >    < 4, 5 >
 * final : < 1, 4, 2, 5, 3 >
 */
template <class T>
void List<T>::shuffle()
{
    // @todo Graded in lab_gdb

    // Find the center, and split the list in half
    // one should point at the start of the first half-list
    // two should point at the start of the second half-list
    ListNode * one, * two, * prev, * temp;
    one = two = prev = temp = head;

    if(head==NULL)//if the list is empty don't do anything
    {
        return;  
    }
    else if(length%2 == 0) //if list length is even
    {

        for (int i = 0; i < length/2; i++)
        {
             prev = two;
             two = two->next;
        }
        prev->next = NULL;

        // interleave
         while (two != NULL)
        {
            temp = one->next;
            one->next = two;
            two = two->next;
            one->next->next = temp;
            one = temp; //added this line
        }
    }
    else if(length%2 == 1)//if list length is odd
    {
    
        for (int i = 0; i < length/2; i++)
        {
            prev = prev->next; //small difference here for case that is odd length
            two = two->next;
        }
        prev->next = NULL;

        // interleave
        while (two != NULL)
        {
            temp = one->next;
            one->next = two;
            two = two->next;
            one->next->next = temp;
            one = temp; //added this line
        }
     }       
}


