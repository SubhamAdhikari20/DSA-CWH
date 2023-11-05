#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top_value;
    char *arr;
};

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

int pop(struct stack *ptr)
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

int parenthesis_match(char *exp){
    // Stack Initializaton
    struct stack *s;
    s->size = 100;
    s->top_value = -1;
    s->arr = (char *) malloc(s->size*sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (!isEmpty(s))
            {
                pop(s);
            } 
            else
            {
                return 0;
            }   
        }  
    }

    if(isEmpty(s))
    {
        return 1;
    }    
    else
    {
        return 0;
    }    
}

int main(){
    char *exp = "4*2-)1-3*4";
    if (parenthesis_match(exp))
    {
        printf("Parenthesis is matching\n");
    }
    else
    {
        printf("Parenthesis is not matching\n");
    }
    return 0;
}