#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top_value;
    char *arr;
};

int stack_top(struct stack *ptr){
    return ptr -> arr[ptr->top_value];
}

int isEmpty(struct stack *ptr){
    if (ptr->top_value == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if (ptr->top_value == ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}


void push(struct stack *ptr, char value)
{
    if (!isFull(ptr))
    {
        ptr->top_value++;
        ptr->arr[ptr->top_value] = value;
    }
    else{
        printf("Stack is full and could result in overflow\n");
    }   
}

char pop(struct stack *ptr)
{
    if (!isEmpty(ptr))
    {
        char poped_value = ptr->arr[ptr->top_value];
        ptr->top_value--;
        return poped_value;
    }
    else{
        printf("Stack is empty and could result in underflow\n");
        return 0;
    }   
}

int precedence(char ch){
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }   
}

int is_operator(char ch){
    if (ch ==  '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

char* infix_to_postfix(char *infix){
    // Stack Initializaton
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 100;
    s->top_value = -1;
    s->arr = (char *) malloc(s->size*sizeof(char));
    char *postfix = (char *) malloc((strlen(infix)+1)*sizeof(char));  // initialization of posfix character array pointer;
    int i = 0;      // initializing counters ----> track infix traversal
    int j = 0;      // initializing counters ----> fill postfix and traversal
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if (isEmpty(s) || precedence(infix[i]) > precedence(stack_top(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }   
    // After the iteration in char array is complete pop out all the elements from the stack and fill it in the postfix array character.    
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    free(s->arr);
    free(s);
    return postfix;    
}

int main(){
    char *exp = "x-y/z-k*d";
    char* postfix = infix_to_postfix(exp);
    printf("Postfix is %s", postfix);
    free(postfix);
    return 0;
}