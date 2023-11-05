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

void push(struct stack *st, int value){
    if (!isFull(st))
    {
        st -> top_value++;
        st -> arr[st->top_value] = value;
        // for (int i = 0; i <= st -> top_value; i++)
        // {
        //     printf("%d  ", st->arr[i]);
        // }
        // printf("\n");
    }
    else{
        printf("Stack is Full. Cannot push element: %d. Will overflow if any element is added\n", value);
    }
}

int pop(struct stack *st){
    if (!isEmpty(st))
    {
        int popped_value = st->arr[st->top_value];
        st -> top_value--;
        return popped_value;
    }
    else{
        printf("Stack is Empty. Can pop elements. Will underflow if element (non in this) is being deleted\n");
        return -1;
    };
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top_value = -1;
    s->arr = (int *) malloc(s->size*sizeof(int));

    // Pushing element manually
    // s->arr[0] = 7;
    // s->top_value++;
    // s->arr[1] = 12;
    // s->top_value++;
    // s->arr[2] = 17;
    // s->top_value++;
    // s->arr[3] = 25;
    // s->top_value++;
    // s->arr[4] = 33;
    // s->top_value++;
    // s->arr[5] = 47;
    // s->top_value++;
    // s->arr[6] = 55;
    // s->top_value++;

    printf("Before pushing, Empty?: %d\n", isEmpty(s));
    printf("Before pushing, Full?: %d\n", isFull(s));
    printf("\n");
    push(s, 84);
    push(s, 78);
    push(s, 56);
    push(s, 11);
    push(s, 23);
    push(s, 45);
    push(s, 37);
    push(s, 8);    // ---> 8 elements so, stack is FULL
    push(s, 12);
    push(s, 24);
    printf("After pushing, Empty?: %d\n", isEmpty(s));
    printf("After pushing, Full?: %d\n", isFull(s));
    
    // printf("Before poping, Empty?: %d\n", isEmpty(s));
    // printf("Before poping, Full?: %d\n", isFull(s));
    // printf("\n");
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // // pop(s);
    // // pop(s);
    // // pop(s);
    // // pop(s);    // ---> 8 elements so, stack is FULL
    // // pop(s);
    // // pop(s);
    // printf("After poping, Empty?: %d\n", isEmpty(s));
    // printf("After poping, Full?: %d\n", isFull(s));
    


    free(s->arr);
    free(s);
    return 0;
}