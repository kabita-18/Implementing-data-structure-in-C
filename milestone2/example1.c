// Write a function to find Second Minimum in a Array * Write a function to find Second Maximum in a Array * Write a fucntion to Sort the Array in the given order



//Logic:
// 1) Will result  Base array being edited 
//Sort in Assending return Arra[1]

//2) Traverse
//Minimum & previous
//Place minimum into previous if minimum is found
// Array is having only 1 variable
    // Array is empty - Not error case. Array contain random/0's 
    // if Size is 0?
    // Input arguments are not as expected 
    // Input Array is NULL
    //Array size is 1
    // All values are same- Canot find
    //Array is not valid pointer- Cannot find

    //Logic

#include <stdio.h>
#include <limits.h>

int get2ndSmallest(int arr[], int n)
{
    int i, first, second;
 
    /* The array must have 2 or more items */
    if (n < 2)
    {
       
        return -1;
    }
 
    first = second = arr[0];
    for (i = 0; i < n ; i ++)
    {
        
        if (arr[i] < first)
        {
            second = first;
            first = arr[i];
        }
 
       
        else if (arr[i] < second && arr[i] != first)
            second = arr[i];
    }
    
    return second;
}
 
int main()
{
    int arr[] = {1, 4, 5, 67, 100, 85, 67, 90, -99};
    int len = sizeof(arr)/sizeof(arr[0]);

    int result = get2ndSmallest(arr, len);
    printf(" second minimum element is:%d",result);

    return 0;
}