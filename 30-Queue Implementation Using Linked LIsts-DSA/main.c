#include <stdio.h>
#include <stdlib.h>

// Global variable
struct Node *front = NULL;
struct Node *back = NULL;

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(){
    if (front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    if (n == NULL){
        free(n);
        return 1;
    }
    else {
        free(n);
        return 0;
    }
}

void enqueue(int value){
    struct Node *n = (struct  Node *) malloc(sizeof(struct Node));
    if (!isFull())
    { 
        n->data = value;
        n->next = NULL;
        if (isEmpty())
        {
            front = back = n;    
        }
        else
        {
            back->next = n;
            back = n;
        }
    }
    else
    {
        printf("QueueOverflow!!! Cannot enqueue element: %d\n", value);
    } 
}

int dequeue(){
    struct Node *ptr = front;
    if (!isEmpty())
    { 
        front = ptr->next;
        int poped_value = ptr -> data;
        free(ptr);
        return poped_value;
    }
    else
    {
        printf("No element to dequeue. QueueUnderflow!!!\n");
        return -1;
    } 
}

void linked_list_traversal(struct Node *ptr)
{
    printf("Printing the element of this linked list:\n");
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }   
    printf("\n"); 
}

int main()
{
    printf("Before enqueue, Empty?: %d\n", isEmpty());
    printf("Before enqueue, Full?: %d\n", isFull());
    
    enqueue(84);
    enqueue(78);
    enqueue(56);
    enqueue(11);
    enqueue(23);
    enqueue(45);
    enqueue(37);  
    
    linked_list_traversal(front);

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    linked_list_traversal(front);

    
    return 0;
}