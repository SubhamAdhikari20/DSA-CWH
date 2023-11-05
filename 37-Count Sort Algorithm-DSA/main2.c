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

int maximum(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max<arr[i])
        {
            max = arr[i];
        } 
    }
    return max;
    
}

void count_sort(int *arr, int n)
{
    int i, j;
    int max_element = maximum(arr, n);

    // Initializing the count array dynamically
    int *count_array = (int *) malloc((max_element+1)*sizeof(int));

    // Initializng the elements of the count_array as "0s"
    for (i = 0; i <= max_element; i++)
    {
        count_array[i] = 0;
    }

    // Incrementing the corresponding index's value of count_array
    for (i = 0; i < n; i++)
    {
        count_array[arr[i]]++;
    }

    i = 0;  // count for "count_array"
    j = 0;  // count for main array "arr"

    while (i <= max_element)
    {
        if (count_array[i] > 0)
        {
            arr[j] = i;     // index of incremented elements from count_array is only copied to the main array
            count_array[i]--;
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
    int arr[] = {4, 3, 9, 1, 4, 8, 7};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    count_sort(arr, n);
    print_array(arr, n);
    return 0;
}