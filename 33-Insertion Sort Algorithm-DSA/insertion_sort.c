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
    for (int i = 1; i < n-1; i++)
    {
        key = arr[i];
        int j = i-1;
        while (arr[j] > key && j>=0)
        {   
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {5,61,89,12,32,45,65,3,6,5,78};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    insertion_sort(arr, n);
    print_array(arr, n);
    return 0;
}