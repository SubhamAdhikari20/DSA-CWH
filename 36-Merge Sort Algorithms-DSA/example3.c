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

void merge(int *A, int low, int mid, int high)
{
    int i, j, k, B[high+1];
    i = low;
    j = mid+1;
    k = low;

    while (i<=mid && j<=high)   // from low index to mid index in "i" or mid+1 to high index in "j" 
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++; k++;
        }
        else
        {
            B[k] = A[j];
            j++; k++;
        } 
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++; k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++; k++;
    }
    
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i]; 
    }
}

void merge_sort(int *A, int low, int high)
{
    int mid;
    if (low<high)   // must be more than one element in the array
    {
        mid = (low+high)/2;
        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int arr[] = {45,23,1,5,32,12,6,88,57,21};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    merge_sort(arr, 0, n-1);
    print_array(arr, n);
    return 0;
}