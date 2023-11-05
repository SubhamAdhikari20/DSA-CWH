#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int partition_procedure(int *arr, int low, int high)
{
    int temp;
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    do
    {
        while (pivot >= arr[i])     
        {
            i++;
        }

        while (pivot < arr[j])     
        {
            j--;
        }
        if (i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i<j);
    
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quick_sort(int *arr, int low, int high)
{
    int partition_index;
    if (low<high)
    {
        partition_index = partition_procedure(arr, low, high);
        quick_sort(arr, low, partition_index-1);
        quick_sort(arr, partition_index+1, high);
    }
}

void merge(int *arr1, int *arr2, int *arr3, int n1, int n2)
{
    int i,j,k;
    i = j = k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++; k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++; k++;
        }
    }

    while (i < n1)
    {
        arr3[k] = arr1[i];
        i++; k++; 
    }

    while (j < n2)
    {
        arr3[k] = arr2[j];
        j++; k++; 
    }
    
    
}

int arr3[] = {};

int main()
{
    int arr1[] = {45,23,1,5,32,12,6,88,57,21};
    int arr2[] = {1,9,4,8,6,23,54,10,9,87};
    int n1 = sizeof(arr1)/sizeof(int);
    int n2 = sizeof(arr2)/sizeof(int);
    print_array(arr1, n1);
    print_array(arr2, n2);
    quick_sort(arr1, 0, n1-1);
    quick_sort(arr2, 0, n2-1);
    // print_array(arr1, n1);
    // print_array(arr2, n2);

    merge(arr1, arr2, arr3, n1, n2);
    print_array(arr3, 20);
    return 0;
}