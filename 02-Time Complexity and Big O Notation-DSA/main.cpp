#include <iostream>
using namespace std;

void reverse(int a1[], int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        swap(a1[start], a1[end]);
        start ++;
        end--;
    }
}

void print(int a1[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[5] = {2, 7, 6, 9, 6};
    reverse(arr, 5);
    print(arr, 5);
    return 0;
}