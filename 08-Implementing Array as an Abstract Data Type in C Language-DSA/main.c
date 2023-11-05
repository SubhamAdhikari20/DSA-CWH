#include <stdio.h>
#include <stdlib.h>

typedef struct my_array{
    int total_size;
    int used_size;
    int *ptr;   // Pointer that points to the first element of the array
}arr;

void create_array(arr *a, int ts, int us){      // creating pointer (*a) that stores the address of the instance object
    // (*a).total_size = ts;
    // (*a).used_size = us;
    // (*a).ptr = (int*) malloc(ts*sizeof(int));     // returns integer pointer to the memory location

    a -> total_size = ts;
    a -> used_size = us;
    a -> ptr = (int*) malloc(ts*sizeof(int));     // returns integer pointer to the memory location
}

void set_value(arr *a){
    int n;
    for (int i = 0; i < a -> used_size; i++){
        printf("Enter the element %d: ", i);
        scanf("%d", &n);
        (a -> ptr)[i] = n;
    }
    
}

void show(arr *a){
    for (int i = 0; i < a -> used_size; i++){
        printf("%d\n", (a -> ptr)[i]);
    }
    
}

int main(){
    arr marks;
    create_array(&marks, 20, 2);   // passing address of the "marks"
    printf("The total_size of the marks is %d\n", marks.total_size);
    printf("'set_value' is being executed\n");
    set_value(&marks);
    printf("'show' is being executed\n");
    show(&marks);
    return 0;
}