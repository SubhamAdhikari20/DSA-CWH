#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_array(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int maxmium_size(int *A, int n)
{
    int max_element = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max_element < A[i])
        {
            max_element = A[i];
        }    
    }
    return max_element;
    
}

void count_sort(int *A, int n)
{
    int i, j;
    // Finding the maximum element in the array "A"
    int max = maxmium_size(A, n);

    // Create the count array
    int *count_array  = (int *) malloc((max+1)*sizeof(int));
    
    // Initialize the element to zero
    for (i = 0; i <= max; i++)
    {
        count_array[i] = 0;
    }
    
    // Incrementing the corresponding "0s" or index's values in "count_array"
    for (i = 0; i < n; i++)
    {
        count_array[A[i]] = count_array[A[i]] + 1;    
    }

    i = 0;     // Counter for "count_array"
    j = 0;     // Counter for given_array i.e "A[]"
    
    while (i<=max)
    {
        if (count_array[i] > 0)
        {
            A[j] = i;
            count_array[i] = count_array[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    
}

int main()
{
    int arr[] = {45,23,1,5,32,12,6,88,57,21};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    count_sort(arr, n);
    print_array(arr, n);
    return 0;
}