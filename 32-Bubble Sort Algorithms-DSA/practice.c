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

void bubble_sort(int *arr, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)       // "for loop" no.of all the passes
    {
        printf("Working on pass no. %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++)     // "for loop" no. of comparisons in each passes.
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }   
        }
        if (isSorted)
        {
            return;
        }
        
    }
}

int main()
{
    int arr[] = {3,23,12,16,45,78,89};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}