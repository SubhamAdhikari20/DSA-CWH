#include <iostream>
using namespace std;

typedef struct my_array{
    int total_size;
    int used_size;
    int *ptr;   // Pointer that points to the first element of the array
}arr;

void create_array(arr *a, int ts, int us){      // creating pointer (*a) that stores the address of the instance object
    a -> total_size = ts;
    (*a).used_size = us;
    int *ptr = new int[ts];
}

int main(){
    arr marks;
    create_array(&marks, 20, 12);   // passing address of the "marks"
    printf("The total_size of the marks is %d", marks.total_size);
    return 0;
}