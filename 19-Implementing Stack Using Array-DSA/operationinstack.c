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

int push(struct stack *st, int value){
    if (!isFull(st))
    {
        st -> top_value++;
        st -> arr[st->top_value] = value;
        for (int i = 0; i <= st -> top_value; i++)
        {
            printf("%d  ", st->arr[i]);
        }
        return 1;
        printf("\n");
    }
    else{
        return 0;
    }
}

int pop(struct stack *st){
    if (!isFull(st))
    {
        int popped_value = st->arr[st->top_value];
        st -> top_value--;
        return popped_value;
        // for (int i = 0; i <= st -> top_value; i++)
        // {
        //     printf("%d  ", st->arr[i]);
        // }
    }
    else{
        return -1;
    };
}

int main(){
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
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
    s->arr[6] = 55;
    s->top_value++;

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
        printf("Stack is not Full\n");
        // push(s, 12);
    } 
    
    int pushed_value = push(s, 88);
    if (pushed_value != 0)
    {
        push(s, 88);
    }
    else{
        printf("Stack will overflow\n");
    }
    
    // int pop_value = pop(s);
    // if (pop_value != -1) {
    //     printf("Popped value: %d\n", pop_value);
    // } 
    // else {
    //     printf("Stack is empty, cannot pop.\n");
    // }
    free(s->arr);
    free(s);
    
    return 0;
}