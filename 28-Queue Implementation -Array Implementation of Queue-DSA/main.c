#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front_index;    // stores indixes        
    int back_index;     // stores indixes
    int *arr;
};

int isEmpty(struct queue *ptr){
    if (ptr->front_index == ptr->back_index)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct queue *ptr){
    if (ptr->back_index == ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *ptr, int value){
    if (!isFull(ptr))
    { 
        ptr->back_index = ptr->back_index+1;
        ptr->arr[ptr->back_index] = value;
        
    }
    else
    {
        printf("QueueOverflow!!! Cannot enqueue element: %d\n", value);
    } 
}

int dequeue(struct queue *ptr){
    if (!isEmpty(ptr))
    { 
        int dequeued_value;
        ptr->front_index = ptr->front_index+1;
        dequeued_value = ptr->arr[ptr->front_index];
        return dequeued_value;    
    }
    else
    {
        printf("No element to dequeue. QueueUnderflow!!!\n");
        return -1;
    } 
}

int main()
{
    struct queue *q;
    q->size = 8;
    q->front_index = -1;
    q->back_index = -1;
    q->arr = (int *) malloc(q->size*sizeof(int));

    printf("Before enqueue, Empty?: %d\n", isEmpty(q));
    printf("Before enqueue, Full?: %d\n", isFull(q));
    printf("\n");
    enqueue(q, 84);
    enqueue(q, 78);
    enqueue(q, 56);
    enqueue(q, 11);
    enqueue(q, 23);
    enqueue(q, 45);
    enqueue(q, 37);
    enqueue(q, 8);    // ---> 8 elements so, queue is FULL
    enqueue(q, 12);
    enqueue(q, 24);
    printf("After enqueue, Empty?: %d\n", isEmpty(q));
    printf("After enqueue, Full?: %d\n", isFull(q));
    printf("\n");

    printf("Before dequeue, Empty?: %d\n", isEmpty(q));
    printf("Before dequeue, Full?: %d\n", isFull(q));
    printf("\n");
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);    // ---> 8 elements so, queue is FULL
    // dequeue(q);
    // dequeue(q);
    printf("After dequeue, Empty?: %d\n", isEmpty(q));
    printf("After dequeue, Full?: %d\n", isFull(q));


    return 0;
}
