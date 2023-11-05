#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top_value;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if (ptr -> top_value == -1)
    {
        return 1;
    }
    else{
        return 0;
    }  
}

int isFull(struct stack *ptr){
    if (ptr -> top_value == ptr -> size-1)
    {
        return 1;
    }
    else{
        return 0;
    }  
}

int stack_top(struct stack *ptr){
    if (!isEmpty){
        int stacktop = ptr -> arr[ptr -> top_value];
        return stacktop; 
    }
    else{
        printf("The stack is empty so, no value can drawn\n");
    }
}

int stack_bottom(struct stack *ptr){
    if (!isEmpty){
        int stackbottom = ptr -> arr[0];
        return stackbottom; 
    }
    else{
        printf("The stack is empty so, no value can drawn\n");
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

    printf("The top most element of stack is %d\n",stack_top(s));

    return 0;
}