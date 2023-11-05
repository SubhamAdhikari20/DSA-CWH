#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top_value;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if (ptr -> top_value == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if (ptr -> top_value == ptr -> size-1){
        return 1;
    }
    else if (ptr -> top_value > ptr -> size-1){
        return -1;
    }
    else{
        return 0;
    }
        
}

int main(){
    // struct stack s;
    // s.size = 40;
    // s.top_value = -1;
    // s.arr = (int *) malloc(s.size*sizeof(int));
    
    struct stack *s;
    s->size = 6;
    s->top_value = -1;
    s->arr = (int *) malloc(s->size*sizeof(int));

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
    // s->arr[6] = 55;
    // s->top_value++;


    // Check if stack is empty;
    if (isEmpty(s)){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is not Empty : contains some values\n");
    }

    // Check if stack is Full;
    if (isFull(s)==1){
        printf("Stack is Full\n");
    }
    else if (isFull(s)==-1){
            printf("Stackoverflow!!!\n");
    }
    else{
        printf("Stack is not Full");
    }

    return 0;
}