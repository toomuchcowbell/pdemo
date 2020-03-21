#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //object.same_as_head();
    //object.same_as_tail();
    //object.greater_than_4();
    //object.sum_all_unique();
    //object.first_to_last();
    //object.remove_last_2();
    //object.remove_after_last_2();
    //object.remove_dem_2s();
    //object.situational_removeAndSum_last2();
    //list newList;
    //object.copy_list_evens(newList);
    //object.evens_average();
    object.sumData_lessthan(10);
    //newList = object.copy_evens();
    

    
    //cout << "The new list created looks like this:";
    //newList.display();
    object.display();  //displays the LLL again!
   
    
    return 0;
}
