#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr, int n)
{
    int key, j;
    for (int i = 1; i <= n-1; i++)
    {   
        key = arr[i];      // element to be insert.
        j = i-1;           // element before the "key" .
        while (arr[j]>key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;     // "j" becomes -1;
    }
    
}

int main()
{   
    //   0      1      2     3     4      5      6
    //   45  |  08     12    65    23     02     33 ---> i = 1, key = 45, j = 0
    //   08     45  |  12    65    23     02     33 ---> 1st pass complete (i=1) 
    
    //   08     45  |  12    65    23     02     33 ---> i = 2, key = 12, j = 1
    //   08     12  |  45    65    23     02     33 ---> 1st pass complete (i=1) 

    // int arr[] = {45,8,12,65,23,2,33};
    int arr[] = {3,23,12,16,45,78,89};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    insertion_sort(arr, n);
    print_array(arr, n);
    return 0;
}