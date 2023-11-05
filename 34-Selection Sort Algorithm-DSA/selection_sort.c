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
    int min_index, temp;
    for (int i = 0; i < n-1; i++)
    {
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

int main()
{
    int arr[] = {5,61,89,12,32,45,65,3,6,5,78};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    selection_sort(arr, n);
    print_array(arr, n);
    return 0;
}