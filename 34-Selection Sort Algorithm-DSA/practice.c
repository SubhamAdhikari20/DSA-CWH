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

void selection_sort(int *arr, int n)
{
    printf("Running selection sort\n");
    int temp, min_index;
    for (int i = 0; i < n-1; i++)
    {
        printf("Working on pass no. %d\n", i);
        min_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }    
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }  
}

void selection_sort_adaptive(int *arr, int n)
{
    printf("Running selection sort\n");
    int temp, min_index;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)
    {
        printf("Working on pass no. %d\n", i);
        isSorted = 1;
        min_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
                isSorted = 0;
            }    
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        if (isSorted)
        {       
            return;
        }
    }  
}

int main()
{
    int arr[]= {45,89,12,3,9,65,23,78};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    // selection_sort(arr, n);
    selection_sort_adaptive(arr, n);
    print_array(arr, n);

    return 0;
}