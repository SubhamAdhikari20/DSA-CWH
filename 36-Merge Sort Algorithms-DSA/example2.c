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

void merge_single_array(int *arr, int *array, int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid+1;
    k = low;
    
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            array[k] = arr[i];
            i++; k++; 
        }
        else
        {
            array[k] = arr[j];
            k++; j++;
        }   
    }

    while (i<=mid)
    {
        array[k] = arr[i];
        i++; k++;
    }

    while (j<=high)
    {
        array[k] = arr[j];
        j++; k++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = array[i];
    }   
}

int array[] = {};
int main()
{
    int arr[] = {3,8,10,12,56,5,21,23,45,96};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    merge_single_array(arr, array, 0, 4, 9);
    print_array(arr, n);
    return 0;
}