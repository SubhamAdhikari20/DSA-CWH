#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n"); 
}

void bubble_sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n-1; i++)           // for the no. of passes
    {   
        printf("Working on pass no. %d\n", i+1);

        for (int j = 0; j < n-1-i; j++)     // for the no. of comparisions in each passes
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;    
            } 
        }
    }  
}

void bubble_sort_adaptive(int arr[], int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)           // for the no. of passes
    {   
        printf("Working on pass no. %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++)     // for the no. of comparisions in each passes
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;    
                isSorted = 0;
            } 
            // else{
            //     isSorted = 1;
            // }
        }
        if (isSorted)
        {
            return;
        }   
    }  
}

int main()
{
    int arr[] = {23, 89, 45, 12, 7, 56};
    // int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr)/sizeof(int);
    // printf("%d", n);
    print_array(arr, n);    // Printing the array before the sorting
    // bubble_sort(arr, n);    // Bubble sort function to sort the array
    bubble_sort_adaptive(arr, n);    // Bubble sort adaptive function to sort the array
    print_array(arr, n);    // Printing the array after the sorting
    return 0;
}