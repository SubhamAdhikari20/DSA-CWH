#include <stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int index_deletion(int arr[], int size, int index){
    for (int i = index; i < size; i++){
        arr[i] = arr[i+1];
    }
    return 1;
}

int main(){
    int arr[50] = {3,6,2,5,1,7,9};
    int size = 7, capacity = 50, index = 3;
    display(arr, size);

    index_deletion(arr,size,index);
    size -= 1;
    display(arr, size);
    return 0;
}