#include <stdio.h>
#include <stdlib.h>

struct stack {
   int size;     
   int top_value;     
   char *arr;     
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

void push(struct stack *ptr, char value){
    if (!isFull(ptr))
    {
        ptr -> top_value++;
        ptr -> arr[ptr->top_value] = value;
    }
    else{
        printf("Stack is Full. Cannot push element: %d. Will overflow if any element is added\n", value);
    }
}

char pop(struct stack *ptr){
    if (!isEmpty(ptr))
    {
        char popped_value = ptr->arr[ptr->top_value];
        ptr -> top_value--;
        return popped_value;
    }
    else{
        printf("Stack is Empty. Can pop elements. Will underflow if element (non in this) is being deleted\n");
        return -1;
    }
}

int parenthesis_match(char *exp){
    // Stack Initialization
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top_value = -1;
    sp->arr = (char *) malloc(sp->size*sizeof(char));
    
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (!isEmpty(sp))
            {
                pop(sp);
            }
            else{
                return 0;
            }    
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else{
        return 0;
    }    
}

int main(){
    char *exp = "4*2-(1-3)*4";
    if (parenthesis_match(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    
    return 0;
}