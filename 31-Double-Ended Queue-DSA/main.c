#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front_index;
    int back_index;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if (ptr->front_index == ptr->back_index)
    {
        return 1;
    }
    else 
    {
        return 0;
    }  
}

int isFull(struct queue *ptr)
{
    if (ptr->back_index == ptr->size-1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }  
}

void enqueue_front(struct queue *ptr, int value)
{
    if (((ptr->front_index) != -1))
    {
        ptr->arr[ptr->front_index] = value;
        ptr->front_index--;
        printf("Enqueued elemnt: %d  at front\n", value);
    }
    else
    {
        printf("Cannot insert element %d from front.\n", value);
    }  
}

void enqueue_back(struct queue *ptr, int value)
{
    if (!isFull(ptr))
    {
        ptr->back_index++;
        ptr->arr[ptr->back_index] = value;
        printf("Enqueued elemnt: %d  at back\n", value);
    }
    else
    {
        printf("Queue is Full. Cannot insert element %d. QUEUE-OVERFLOW will occur\n", value);
    }  
}

int dequeue_front(struct queue *ptr)
{
    int dequeued_element;
    if (!isEmpty(ptr))
    {
        ptr->front_index++;
        dequeued_element = ptr->arr[ptr->front_index];
        return dequeued_element;
    }
    else
    {
        printf("Queue is Element. Cannot delete element. OVERFLOW will occur\n");
        return-1;
    }  
}

int dequeue_back(struct queue *ptr)
{
    int dequeued_element;
    if (!isEmpty(ptr))
    {
        dequeued_element = ptr->arr[ptr->back_index];
        ptr->back_index--;
        return dequeued_element;
    }
    else
    {
        printf("Cannot delete element %d from back.\n");
        return-1;
    }  
}

void print_queue(struct queue *ptr)
{
    for (int i = ptr->front_index+1; i < ptr->back_index+1; i++)
    {
        printf("%d  ", ptr->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue *q = (struct queue *) malloc(sizeof(struct queue));
    q->front_index = -1;
    q->back_index = -1;
    q->size = 8;
    q->arr = (int *) malloc(q->size*sizeof(int));

    printf("Before enqueue_back, is queue Empty?: %d\n", isEmpty(q));
    printf("Before enqueue_back, is queue Full?: %d\n", isFull(q));
    enqueue_back(q, 89);
    enqueue_back(q, 45);
    enqueue_back(q, 7);
    enqueue_back(q, 12);
    enqueue_back(q, 66);
    enqueue_back(q, 23);
    enqueue_back(q, 41);
    print_queue(q);
    printf("Dequeued Element: %d  from front\n", dequeue_front(q));
    printf("Dequeued Element: %d  from back\n", dequeue_back(q));
    enqueue_front(q, 123);
    enqueue_front(q, 32);
    enqueue_front(q, 33);
    printf("Dequeued Element: %d  from front\n", dequeue_front(q));
    printf("Dequeued Element: %d  from front\n", dequeue_front(q));
    printf("Dequeued Element: %d  from back\n", dequeue_back(q));
    printf("Dequeued Element: %d  from back\n", dequeue_back(q));
    print_queue(q);
    // enqueue_back(q, 74);
    printf("After enqueue_back, is queue Empty?: %d\n", isEmpty(q));
    printf("After enqueue_back, is queue Full?: %d\n", isFull(q));


    free(q->arr);
    free(q);
    return 0;
}

/* Double Ended Queue (DE Queue) 
Types:
1. Restricted Input DE Queue:
Not Allowed:
-Insertion from "front" is prohibited 
Allowed:
-Insertion and Deletion from "back" is allowed
-Deletion from "front" is allowed

2. Restricted Output DE Queue:
Not Allowed:
Deletion from "back" is prohibited
Allowed:
-Insertion and Deletion from "front" is allowed
-Insertion from "back" is allowed
*/ 