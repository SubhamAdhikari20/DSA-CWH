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

int partition_procedure(int *arr, int low, int high)     // returns the partition_index
{
    int temp;
    int pivot = arr[low];
    int i = low+1;  // index after the pivot to compare if element at i is greater than pivot element till it satisfies the condition    // we increment "i"
    int j = high;   // index of the end element of the array to compare if element at j is less than pivot element till it satisfies the condition  // we decrement "j"

    do
    {
        while (arr[i] <= pivot)     // till "arr[i]" element is greater than pivot element
        {
            i++;
        }

        while (arr[j] > pivot)     // till "arr[j]" element is less than pivot element
        {
            j--;
        }
        
        if (i<j)    // swaping element "a[i]" and element "a[j]" at that index
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i<j);

    // swap arr"[low]" with "arr[j]"
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;   // index of pivot after partition prodecure
}

void quick_sort(int *arr, int low, int high)
{   
    int partition_index;    // index of pivot after partition prodecure
    
    if (low < high)   // some element must me there in the array to run the following
    {
        partition_index = partition_procedure(arr, low, high);
        quick_sort(arr, low, partition_index-1);    // sort left sub-array // Note:  low = low, high = partition_index    
        quick_sort(arr, partition_index+1, high);   // sort right sub-array // Note: low = partition_index, high = high;
    }
}

int main()
{
    int arr[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    quick_sort(arr, 0, n-1);
    print_array(arr, n);
    return 0;
}