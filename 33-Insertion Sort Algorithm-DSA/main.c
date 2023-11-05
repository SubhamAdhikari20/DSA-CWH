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
    // loop for all passes
    for (int i = 1; i <= n-1; i++)
    {   
        key = arr[i];         // index of Inserting element
        j = i-1;              // index of element ahead of Inserting element  

        // loop for each pass
        while (arr[j] > key && j>=0)       // "arr[j]" are the elements before the "key"
        {
            arr[j+1] = arr[j];
            j--;
        }    
        arr[j+1] = key;
    }   
}

int main()
{
    //  -1   0    1    2   3   4   5
    //      89,| 23,  45, 12, 07, 56 --> i=1, key = 23, j=0
    //      23,  89,| 45, 12, 07, 56 --> 1st pass complete (i=1)
    
    //      23,  89,| 45, 12, 07, 56 --> i=2, key = 45, j=1
    //      23,  45,  89,|12, 07, 56 --> 2nd pass complete (i=2)
    
    //      23,  45,  89,|12, 07, 56 --> i=3, key = 12, j=2
    //      23,  45,  89,|89, 07, 56 --> i=3, key = 12, j=1
    //      23,  45,  45,|89, 07, 56 --> i=3, key = 12, j=0
    //      23,  23,  45,|89, 07, 56 --> i=3, key = 12, j=-1 
    //      12,  23,  45,|89, 07, 56 --> i=3, key = 12, j=-1 (+1)
    //      12,  23,  45, 89,|,07,56 --> 3rd pass complete (i=3)
    
    //      12,  23,  45, 89,|,07,56 --> i=4, key = 7, j=3
    //      12,  23,  45, 89,|,89,56 --> i=4, key = 7, j=2
    //      12,  23,  45, 45,|,89,56 --> i=4, key = 7, j=1
    //      12,  23,  23, 45,|,89,56 --> i=4, key = 7, j=0
    //      12,  12,  23, 45,|,89,56 --> i=4, key = 7, j=-1
    //      01,  12,  23, 45,|,89,56 --> i=4, key = 7, j=-1 (+1)
    //      07,  12,  23, 45, 89,|,56 --> 4th pass complete (i=4)
    
    //      07,  12,  23, 45, 89,|,56 --> i=5, key = 56, j=4
    //      07,  12,  23, 45, 89,|,89 --> i=5, key = 56, j=3
    //      07,  12,  23, 45, 56,|,89 --> i=5, key = 56, j=3 (+1)
    //      07,  12,  23, 45, 56,  89,| --> 5th pass complete (i=5)

    int arr[] = {89, 23, 45, 12, 7, 56};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    insertion_sort(arr, n);
    print_array(arr, n);
    return 0;
}