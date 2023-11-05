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
        printf("Working on pass no. %d\n", i);
        min_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }    
        }
        // int j = i+1;
        // while (arr[min_index] > arr[j] && j < n)
        // {
        //     min_index = j;
        //     j++;
        // }
    
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;   
    }
    
}
void selection_sort_adaptive(int *arr, int n)
{
    int min_index, temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)
    {
        printf("Working on pass no. %d\n", i+1);
        isSorted = 1;
        min_index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[min_index]>arr[j])
            {
                min_index = j;
                isSorted = 0;
            }    
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;   
        if (isSorted)
        {
            return;
        }
        
    }
    
}

int main()
{
    // Input array: (--> total "n-1 passes" will be there because last element doesnot require sorting as will always be in its right position);
    //  01     02     03     04     05   ---> Index
    // |08     00     07     01     03

    // After first pass:
    // 01      02     03     04     05   ---> Index
    // 00  |   08     07     01     03     
    
    // After second pass:
    // 01     02     03     04     05   ---> Index
    // 00     01  |  07     08     03     
    
    // After third pass:
    // 01     02     03      04     05   ---> Index
    // 00     01     03  |   08     07     
    
    // After fourth pass:
    // 01     02     03     04      05   ---> Index
    // 00     01     03     07   |  08     


    int arr[] = {8,0,7,1,3};
    int n = sizeof(arr)/sizeof(int);
    print_array(arr, n);
    // selection_sort(arr, n);
    selection_sort_adaptive(arr, n);
    print_array(arr, n);
    return 0;
}
