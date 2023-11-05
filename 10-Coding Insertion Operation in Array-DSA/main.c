#include <stdio.h>

// Traversal
void display(int arr[], int x){
    for (int i = 0; i < x; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// Insertion
int index_inserton(int arr[], int size, int ele, int capacity, int index){
    if (size>=capacity){
        return -1;
    }
    for (int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = ele;
    return 1;
}

int main(){
    int arr[100] = {2,8,5,10,3};
    int size = 5, capacity = 100;
    display(arr, size);

    // Insertion
    int ele = 7, index = 3;
    index_inserton(arr, size, ele, capacity, index);
    size += 1;
    display(arr, size); 
    

    return 0;
}