//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   		//These functions are already written
   		list();			//supplied
   		~list();		//supplied
   		void build();	//supplied
   		void display();	//supplied

        //Write your function prototypes below. My suggestion is to do one at a time and comment them out. at the end test them a few
        //times to see if they work on different datasets...

        int same_as_head(); //count the number of items in the list that are the same as the first node and return the count.
        int same_as_tail(); //count the number of items in the list that are the same as the last node and return the count.
        int greater_than(int value); //count the number of items in the list that are greater than 4 and return the count. do this as a general number though, as a parameter
        int sum_unique(); //display all the unique data that exists in the data structure and return the sum of all unique items.
        int front_to_back(); //remove the first node and place it at the end of the list; return the number of items in the list.
        int count_remove_last(int value); //remove the last '2' and return the total number of 2's in the list. Do this in only a single traversal. Make this callable to any integer value.
        //remove all nodes after the last '2' and return the number of nodes removed. do in single traversal.
        //remove every '2' except the first one. return the number of nodes removed. single trav.
        //remove the last two nodes, but only if the last one is not a '2'. Return the sum of these nodes.
        //make a copy of the data structure, but only copy even data. return the number of nodes copied. Do not implement this with an insert function, traverse only once.
        //create an average of all the even data in the data structure.
        //sum all of the data less than 10 in the data structure.
        //make a copy of all even data items.
        //make a copy of all unique data.


	private:
		node* rear;

        //private functions for recursion here:
        int same_as_head(node* head, int key);
        int same_as_tail(node* head, int key); 
        int greater_than(node* head, int key); 
        bool is_unique(node* head, node* &keyNode);
        int sum_unique(node* head);
        int front_to_back(node* head);

};
