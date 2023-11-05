#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top_value;
    int *arr;
};

int peek(struct stack *ptr, int i){     // i ---> position
    int array_index = ptr->top_value-i+1;
    if (array_index < 0)
    {
        printf("Invalid Position");
        return -1;
    }
    else{
        return ptr->arr[array_index];
    }
    
}

int main(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 6;
    s->top_value = -1;
    s -> arr = (int *) malloc(s->size*sizeof(int));
    
    // Pushing element manually
    s->arr[0] = 7;
    s->top_value++;
    s->arr[1] = 12;
    s->top_value++;
    s->arr[2] = 17;
    s->top_value++;
    s->arr[3] = 25;
    s->top_value++;
    s->arr[4] = 33;
    s->top_value++;
    s->arr[5] = 47;
    s->top_value++;
    
    for (int i = 1; i <= s->top_value+1; i++)
    {
        printf("The peeked element at position %d is %d\n",i,peek(s,i));
    }
    
    return 0;
}