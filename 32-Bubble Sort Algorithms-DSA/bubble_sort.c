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
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }  
        }  
          
    }
    
}


int main()
{
    int arr[] = {5,61,89,12,32,45,65,3,6,5,78};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}