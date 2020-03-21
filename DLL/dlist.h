//doubly linked lisj
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied

        /* *****************YOUR TURN! ******************************** */
        /* place your prototypes here */

        int same_as_head(); //count the number of items in the list that are the same as the first node and return the count.
        int same_as_tail(); //count the number of items in the list that are the same as the last node and return the count.
        int greater_than_4(); //count the number of items in the list that are greater than 4 and return the count.
        //display all the unique data that exists in the data structure and return the sum of all unique items.
        //remove the first node and place it at the end of the list; return the number of items in the list.
        //remove the last '2' and return the total number of 2's in the list. Do this in only a single traversal.
        //remove all nodes after the last '2' and return the number of nodes removed. do in single traversal.
        //remove every '2' except the first one. return the number of nodes removed. single trav.
        //remove the last two nodes, but only if the last one is not a '2'. Return the sum of these nodes.
        //make a copy of the data structure, but only copy even data. return the number of nodes copied. Do not implement this with an insert function, traverse only once.
        //create an average of all the even data in the data structure.
        //sum all of the data less than 10 in the data structure.
        //make a copy of all even data items.
        //make a copy of all unique data.
        
     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
};
