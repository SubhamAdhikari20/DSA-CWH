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
    for (int i = 0; i < size; i++)
    {
        if (arr[0] == n || arr[-1] == n){
            // printf("index");
            return arr[n];
    }
        else if (arr[0] != n || arr[-1] != n){
            int mid = (arr[0] + arr[-1])/2;
            if (n == mid){
                return mid;
            } 
            else if (n > mid){
                
            }
            else{
            
            
            }
                
        } 
    }
    
    if (arr[0] == n || arr[-1] == n){
        // printf("index");
        return arr[n];
    }
    else if (arr[0] != n || arr[-1] != n){
        int mid = (arr[0] + arr[-1])/2;
        if (n == mid){
            return mid;
        } 
        else if (n > mid){
            
        }
        else{
            
            
            }
                
        }    

    }
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
   int ele = 47;
   int index_binary_search = binary_search(arr, size, ele);

    return 0;
}