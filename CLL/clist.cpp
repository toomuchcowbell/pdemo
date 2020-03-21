//list.cpp
#include "clist.h"

//*************************************************
//*************************************************
//*************************************************
//*************************************************
//functions related to same_as_head
int list::same_as_head()
{
    if (rear == NULL)
        return 0;
    int key = rear->next->data;
    int same_count = same_as_head(rear->next, key);
    if (same_count == 0)
        cout << "There were no matches to the head node's data in the list." << endl;
    else 
        cout << "The number of nodes in the list that match the head node is: " << same_count << endl;
    return same_count;
}
int list::same_as_head(node* head, int key)
{
    if (head == rear)
    {
        if (head->data != key)
            return 0;
        if (head->data == key)
            return 1;
    }
    if (head->data == key && head != rear->next)
        return same_as_head(head->next, key) + 1;
    else 
        return same_as_head(head->next, key);
}
//*************************************************
//*************************************************
//*************************************************
//*************************************************
//functions related to same_as_tail
int list::same_as_tail()
{
    if (rear == NULL) 
       return 0;
    int key = rear->data;
    int same_count = same_as_tail(rear->next, key);
    if (same_count == 0)
        cout << "There were no nodes in the list with the same data as the tail node." << endl;
    else
        cout << "The number of nodes with the same data as the tail is: " << same_count << endl;
    return same_count;

}
int list::same_as_tail(node* head, int key)
{
    if (head == rear)
    {
        return 0;
    }
    if (head->data == key)
        return same_as_tail(head->next, key) + 1;
    else return same_as_tail(head->next, key);
}
//*************************************************
//*************************************************
//*************************************************
//*************************************************
//functions related to greater_than
int list::greater_than(int value)
{
    if (rear == NULL) return 0;
    int node_count = greater_than(rear->next, value);
    if (node_count == 0)
        cout << "There were no nodes greater than " << value << " in the list." << endl;
    else
        cout << "There were " << node_count << " nodes greater than " << value << " in the list." << endl;
    return node_count;
}
int list::greater_than(node* head, int key)
{
    if (head == rear)
    {
        if (head->data > key)
            return 1;
        else
            return 0;
    }
    if (head->data > key)
        return greater_than(head->next, key) + 1;
    else
        return greater_than(head->next, key);
}
//*************************************************
//*************************************************
//*************************************************
//*************************************************
//functions related to sum_unique
int list::sum_unique()
{
    if (rear == NULL)
        return 0;
    int sum = sum_unique(rear->next);
    if (sum == 0)
        cout << "There were no unique numbers in the list." << endl;
    else 
        cout << endl << "The sum of all the unique numbers is: " << sum << endl;
    return sum; 
}
int list::sum_unique(node* head)
{
    if (head == rear)
    {
        if (is_unique(head->next, head))
        {
            cout << " -> " << head->data;
            return head->data;
        }
        else
            return 0; 
    }
    if (is_unique(head->next, head))
    {
        if (head == this->rear->next)
            cout << head->data;
        else if (head == this->rear->next->next && (!is_unique(head, this->rear->next)))
            cout << head->data;
        else
            cout << " -> " << head->data;
        return sum_unique(head->next) + head->data;
    }
    else
        return sum_unique(head->next);
}
bool list::is_unique(node* head, node* &keyNode)
{
    if (head == keyNode)
        return true;
    if (head->data == keyNode->data)
        return false;
    return is_unique(head->next, keyNode);
}
//*************************************************
//*************************************************
//*************************************************
//*************************************************
//functions related to front_to_back
int list::front_to_back()
{
    int count = front_to_back(rear->next);
    if (count == 0)
        cout << "There is nothing in the list. It's empty." << endl;
    else
        cout << "There are " << count << " items in the list." << endl;
    return count;
}

int list::front_to_back(node* head)
{
    if (head == rear)
    {
        rear = rear->next;
        return 1;
    }
    else return front_to_back(head->next) + 1;
}

