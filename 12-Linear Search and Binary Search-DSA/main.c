#include <stdio.h>

int linear_search(int arr[], int size, int n){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n ){
            // printf("index");
            return i;
        }
    }
    return -1;  
}

int binary_search(int arr[], int size, int n){
    int low, mid, high;
    low = 0;
    high = size-1;
    
    // Searching Starts
    // keep searching till low and high converges
    while (low <= high){
        mid = (low + high)/2;
        if (arr[mid] == n){
            return mid;
        }
        else if (arr[mid] < n){
            low = mid+1;
            // mid = (low + high)/2;
            
        }
        else{
            high = mid-1;
            // mid = (low + high)/2;

        }
    }
    // Searching Ends

    return -1;  
}


int main(){
    /*
    int arr[] = {4,8,1,6,3,9,7,5};
    int size = sizeof(arr)/sizeof(int);
    int ele = 6;
    int index_linear_search = linear_search(arr, size, ele);
    printf("The element %d was found in index %d \n", ele, index_linear_search);
    */

   int arr[] = {2,5,8,9,10,13,14,25,47,64,79};
   int size = sizeof(arr)/sizeof(int);
   int ele = 8;
   int index_binary_search = binary_search(arr, size, ele);
    printf("The element %d was found in index %d \n", ele, index_binary_search);
    return 0;
}