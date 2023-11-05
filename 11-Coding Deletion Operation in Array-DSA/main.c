#include <stdio.h>

// Traversal
void display(int arr[], int x){
    for (int i = 0; i < x; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// Deletion
int index_deletion(int arr[], int size,int index){
    for (int i = index; i < size ; i++){
        arr[i] = arr[i+1];
    }
    return 1;
}

int main(){
    int arr[100] = {2,8,5,10,3};
    int size = 5, capacity = 100;
    display(arr, size);

    // Deletion
    int ele = 5, index = 2;
    index_deletion(arr, size, index);
    size -= 1;
    display(arr, size); 

   
    return 0;
}