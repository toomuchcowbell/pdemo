//list.cpp
#include "list.h"

//*************************************************
//functions related to same_as_head
int list::same_as_head()
{
    int key = head->data;
    int num_returned = same_as_head(head, key);
    if (num_returned >= 1)
        --num_returned;
    cout << "The number of nodes that match the head node is: " << num_returned << endl;
    return num_returned;
}
//gets the number of occurences of the first node->data
int list::same_as_head(node* head, int key)
{
    if(head == NULL) 
        return 0;
    if(head->data == key)
        return same_as_head(head->next, key) + 1;
    else
        return same_as_head(head->next, key);
}
//*************************************************




//*************************************************
//functions related to: same_as_tail

int list::same_as_tail()
{
    int key = find_key(head);
    int num_returned = same_as_tail(head, key);
    if (num_returned >= 1)
        --num_returned;
    cout << "The number of nodes that match the tail node is: " << num_returned << endl;
    return num_returned;
}

int list::find_key(node* head)
{
    if (head == NULL) return 0;
    if (head->next == NULL)
        return head->data;
    return find_key(head->next);
}

int list::same_as_tail(node* head, int key)
{
    if (head == NULL)
        return 0;
    int numOccurences = same_as_tail(head->next, key);
    if (head->data == key)
        return ++numOccurences;
    else
        return numOccurences;
}

//*************************************************
//functions related to greater_than_4
int list::greater_than_4()
{
   int theCount = greater_than_4(head);
   cout << "The number of items in the list greater than 4 is: " << theCount << endl;
   return theCount; //it is referencing this->head
}

int list::greater_than_4(node* head)
{
   if (head == NULL) return 0;
   if (head->data > 4) 
           return greater_than_4(head->next) + 1;// if the data is greater than 4 increment count and continue recursion
   else return greater_than_4(head->next);
}
//*************************************************



//*************************************************
//functions related to sum_all_unique
int list::sum_all_unique()
{
    int sum = 0;
    bool firstNode = true;
    if (head == NULL)
        return sum;
    cout << "The array after removing non-unique numbers is as follows: ";
    sum = sum_all_unique(head, firstNode);
    cout << "The sum of these items is: " << sum << endl;
    return sum;
}

bool list::is_unique(node* head, node* keyNode)
{
    if (head == NULL)
        return true;
    if (head->data == keyNode->data && head != keyNode)
        return false;
    bool theTest = is_unique(head->next, keyNode);
    return theTest;
}
int list::sum_all_unique(node* head, bool firstNode)
{
    if (head == NULL) 
    {
        cout << endl;
        return 0;
    }
    if (is_unique(this->head, head))// if the number's unique, print it.
    {
        if (firstNode) // if it's the first just flip to false otherwise add arrow
            firstNode = false;
        else cout << " -> ";
        cout << head->data; // then print data 
    }
    else return sum_all_unique(head->next, firstNode);//otherwise step to next node.  
    return sum_all_unique(head->next, firstNode) + head->data;
}
//*************************************************



//*************************************************
//functions related to front_to_back
int list::first_to_last()
{
    if (head == NULL)
        return 0;
    int nodeCount = first_to_last(head, head);
    cout << "The list has a total of: " << nodeCount << " nodes. The first has been moved to the back." << endl;
    return nodeCount;
}
int list::first_to_last(node* head, node* movePointer)
{
    if (head == NULL)
        return 0;
    else if (this->head == movePointer && head->next != NULL)
    {
        this->head = head->next;
    }
    int count = first_to_last(head->next, movePointer) + 1;
    if (head->next == NULL)
    {
        head->next = movePointer;
        movePointer->next = NULL;
    }
    return count;
}
//*************************************************



//*************************************************
//functions related to remove_last_2()
int list::remove_last_2()
{
    if (head == NULL) return 0;
    node* myMarker = NULL;
    int nodeCount = remove_last_2(head, myMarker);
    cout << "After removing the last occurence of 2, the list contains: " << nodeCount << " nodes." << endl;
    return nodeCount;
}


//in case you're wondering, I am not a fan of how i recursed BACK up the recursion, I just solved the problem and moved on
//with this one because diminishing returns can't justify the time I spend on it
int list::remove_last_2(node* head, node* &marker) 
{
    if (head == NULL) 
        return 0;
    if (head->data == 2) 
        marker = head;
    int count = remove_last_2(head->next, marker) + 1;
    if (marker == NULL)
        return count;
    else if (head->next == marker)
    {
        if (marker->next == NULL)
        {
            head->next = NULL;
            tail = head;
            delete marker;
            marker = NULL; 
        }
        else
        {
            head->next = marker->next;
            delete marker;
            marker = NULL;
        }
        return --count;
    }
    else
        return count;
}
//*************************************************



//*************************************************
//functions related to remove_after_last_2()
int list::remove_after_last_2()
{
    if (head == NULL) return 0;
    node* myMarker = NULL;
    int nodeCount = remove_after_last_2(head, myMarker);
    cout << "You used a function that removes all nodes after the last occurrence of 2." << endl;
    cout << nodeCount << " nodes were removed from the list." << endl;
    return nodeCount;
}
int list::remove_after_last_2(node* head, node* &marker)
{
    if (head == NULL) 
        return 0;
    if (head->data == 2) 
        marker = head;
    int count = remove_after_last_2(head->next, marker);
    if (marker == NULL || head->next == NULL || marker == tail) 
        return count; //if the marker is not set, or if you are at the end of the list or the marker is at the last item
                      //then you can't delete anything... so return current count.
    else if(head == marker) //if you're at the marker(the last 2), set tail to that and delete the next node, increment count.
    {
        tail = head;
        delete head->next;
        head->next = NULL;
        marker = NULL;
        return ++count;
    }
    else //if you're not at the last marker on the way back up and there's a node to delete, do that and increment count;
    {
        if (head->next != NULL)
        {
            delete head->next;
            head->next = NULL;
            return ++count;
        }
        else return count;
    }    
}
//*************************************************



//*************************************************
//functions related to remove_dem_2s()
int list::remove_dem_2s()
{
    if (head == NULL) return 0;
    node* myMarker = NULL;
    int removalCount = remove_dem_2s(head, myMarker);
    cout << "All nodes that were repetitions of the first '2' were removed from the list. " << endl;
    cout << removalCount << " nodes were thus removed from this list." << endl;
    return removalCount;
}

int list::remove_dem_2s(node* head, node* &marker)
{
    if (head == NULL)
        return 0;
    if (marker == NULL && head->data == 2)
        marker = head;
    int counter = remove_dem_2s(head->next, marker);
    if (head->next != NULL) 
    {
        if (head->next->data == 2 && head->next != marker)//if this is a node to remove, remove it and increment counter
        {
            if(head->next == tail)
            {
                //in this case we need to reset tail.
                tail = head;
                delete head->next;
                head->next = NULL;
            }
            else
            {
                //here we delete a node in between the 2
                node* temp;
                temp = head->next;
                head->next = head->next->next;
                delete temp;
            }
            return ++counter;
        }
    }
    return counter;
}
//*************************************************



//*************************************************
//functions related to situational_removeAndSum_last2() 
int list::situational_removeAndSum_last2()
{
    node* myMarker = NULL;
    int sum = monstrosity(head, myMarker);
    if (sum == 0)
        cout << "The last 2 nodes were not removed from the list because the last node was not a 2" << endl;
    else
        cout << "The sum of the last 2 nodes that were removed from the list is: " << sum << endl;
    return sum;
}

int list::monstrosity(node* head, node* &marker)
{
    if (head == NULL) return 0;
    if (head != tail)
        if (head->next == tail && tail->data == 2)
            marker = head;
    int sum = monstrosity(head->next, marker);
    if (marker == NULL)
        return sum;
    else if(marker != NULL && head->next == marker) 
        {
            sum = marker->data + marker->next->data;
            tail = head;
            delete marker->next;
            delete marker;
            marker = NULL;
            head->next = NULL;
        }
    return sum;
}
//*************************************************



//*************************************************
//functions related to copy_list_evens() 
int list::copy_list_evens(list& destination)
{
    int size = copy_list_evens(head, destination.head, destination);
    if (size == 0) 
        cout << "No nodes in the list were even, so none were copied" << endl;
    else 
        cout << "The size of the new list with only the even numbers is: " << size << endl;
    return size;
}

int list::copy_list_evens(node* head, node* dest, list& destList)
{
    if(head == NULL)
    {
        destList.tail = dest; // to do this is the only reason i'm using destList in the recursion...
        return 0;             // couldn't readily think of a better way to do this without mucking up the
                              // definition of the problem
    }
    if ((head->data % 2) == 0)
    {
        if (dest == NULL) // if the list is currently empty.
        {
            dest = new node;
            destList.head = dest;
            dest->data = head->data;
            dest->next = NULL;
            //destList.head = dest;
            return copy_list_evens(head->next, dest, destList) + 1;
        }
        else { // if there's stuff in list, we're gonna add a node and increment dest, get where i'm going?
            dest->next = new node;
            dest->next->data = head->data;
            dest->next->next = NULL;
            return copy_list_evens(head->next, dest->next, destList) + 1;
        }
    }
    else
        return copy_list_evens(head->next, dest, destList);
}
//*************************************************



//*************************************************
//functions related to evens_average() 
int list::evens_average()
{
    int sum(0), avg(0);
    int numNodes = evens_average(head, sum);
    if (sum == 0)
    {
        cout << "There were no even numbers in the list." << endl;
        avg = sum;
    }
    else
    {
        avg = sum/numNodes;
        cout << "The average of the even numbers is approximately: " << avg << endl;
    }
    return avg;
}

int list::evens_average(node* head, int& sum)
{
    if (head == NULL) 
        return 0;
    else if ((head->data % 2) == 0)
    {
        sum = sum + head->data;
        return evens_average(head->next, sum) + 1;
    }
    else return evens_average(head->next, sum);
}
//*************************************************



//*************************************************
//functions related to sumData_lessthan(int threshold)
int list::sumData_lessthan(int threshold)
{
    int sum = sumData_lessthan(head, threshold);
    if (sum == 0)
        cout << "There was no value in the list less than " << threshold << endl;
    else
        cout << "The sum of data of items in this list less than " << threshold << " is: " << sum << endl;
    return sum;
}

int list::sumData_lessthan(node* head, int threshold)
{
    if (head == NULL) return 0;
    if (head->data < threshold)
        return sumData_lessthan(head->next, threshold) + head->data;
    else return sumData_lessthan(head->next, threshold);
}
//*************************************************



//*************************************************
//functions related to copy_evens()
list& list::copy_evens()
{
    list* destination = new list;
    int numEvensCopied = copy_evens(head, destination->head, *destination);
    if (numEvensCopied == 0)
        cout << "It seems there were no evens in the list to be copied. The list is empty" << endl;
    else
        cout << "The list has been populated with " << numEvensCopied << " of the even items." << endl;
    return *destination;   
}

int list::copy_evens(node* head, node* dest, list& destList)
{
   if (head == NULL) 
   {
       destList.tail = dest;
       return 0; 
   }
   if ((head->data % 2) == 0) // if the number is even...
   {
       if(dest == NULL) // if the list is empty...
       {
           dest = new node;
           destList.head = dest;
           dest->data = head->data;
           dest->next = NULL;
           return copy_evens(head->next, dest, destList) + 1;
       }
       else {
           dest->next = new node;
           dest->next->next = NULL;
           dest->next->data = head->data;
           return copy_evens(head->next, dest->next, destList) + 1;
       }
   }
   else return copy_evens(head->next, dest, destList);
}


