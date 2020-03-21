//arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//for practicing arrays of linear linked lists
//dont use loops, rather use pointers for access to elements
//of the array!

struct node
{
    int data;           //some questions are char * data;
    node * next;
};

class table
{
    public:
    /* These functions are already written */
       table();		    //supplied
       ~table();	    //supplied
       void build();  	//supplied
       void display();  //supplied

    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    //count the number of items in a LLL and return the count
    //display the last item in each LLL and return the count
    //display all the data in the last LLL and return the largest item
    //compare the first node in each LLL and return true if they are the same
    //remove the first node in each LLL and return the sum of each
    //remove the last node in each LLL and return the number of nodes removed

    private:
       node ** head; 	//dynamically allocated array
       int size; 	//the array size
};
