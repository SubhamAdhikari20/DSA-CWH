#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr){
    if (ptr == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node *ptr){
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    if (n == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

struct Node * push(struct Node *ptr, int value){
    if (!isFull(ptr))
    {
        struct Node *n = (struct Node*) malloc(sizeof(struct Node));
        n -> data = value;
        n -> next = ptr;
        ptr = n;
        return ptr;
    }
    else{
        printf("Stack is Full. Cannot push element: %d. Will overflow if any element is added\n", value);
    }
    return ptr;
}

int pop(struct Node **ptr){
    if (!isEmpty(*ptr))
    {   
        struct Node *n = *ptr;
        *ptr = (*ptr) -> next;
        int poped_value = n -> data;
        free(n);
        return poped_value;
    }
    else{
        printf("Stack is Empty. Can pop elements. Will underflow if element (non in this) is being deleted\n");
    }
}

void linked_list_traversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d  ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main(){
    struct Node *top_ptr = NULL;
    top_ptr = push(top_ptr, 45);
    top_ptr = push(top_ptr, 12);
    top_ptr = push(top_ptr, 78);
    top_ptr = push(top_ptr, 99);
    linked_list_traversal(top_ptr);
    printf("\n");
    
    int pop_element1 = pop(&top_ptr);
    printf("The poped element is %d\n", pop_element1);
    int pop_element2 = pop(&top_ptr);
    printf("The poped element is %d\n", pop_element2);
    linked_list_traversal(top_ptr);
    return 0;
}