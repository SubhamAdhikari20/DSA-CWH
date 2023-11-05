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

void merge_single_array(int *arr, int low, int mid, int high, int *array)
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
            i++;
            k++;
        }
        else
        {
            array[k] = arr[j];
            j++;
            k++;
        }   
    }

    while (i <= mid)
    {
        array[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        array[k] = arr[j];
        j++;
        k++;
    } 

    for (int i = low; i <= high; i++)
    {
        arr[i] = array[i];
    }        
}

void merge_sort(int *arr, int low, int high, int *array)
{
    int mid;
    if (low < high)
    {
        mid = (low+high)/2;
        merge_sort(arr, low, mid, array);
        merge_sort(arr, mid+1, high, array);
        merge_single_array(arr, low, mid, high, array);
    }
    
}

int array[] = {};
int main()
{
    // int arr[] = {2, 3, 4, 9, 1, 4, 5, 6, 7, 8};
    // int n = sizeof(arr)/sizeof(int);
    // print_array(arr, n);
    // merge_single_array(arr, 0, 3, 9, array);
    // print_array(arr, 10);

    int arr[] = {7, 1, 2, 8};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    merge_sort(arr, 0, 3, array);
    print_array(arr, n);
    
    return 0;
}