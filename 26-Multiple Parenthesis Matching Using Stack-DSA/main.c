#include <stdio.h>
#include <stdlib.h>

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

int match(char a, char b){
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;

}

int parenthesis_match(char *exp){
    // Stack Initializaton
    struct stack *s;
    s->size = 100;
    s->top_value = -1;
    s->arr = (char *) malloc(s->size*sizeof(char));
    char poped_ch;
    
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);  
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (!isEmpty(s))
            {
                poped_ch = pop(s);
                if (!match(poped_ch, exp[i]))
                {
                    return 0;
                }
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
    char *exp = "{7-(3-2})+8*[99-11])";
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