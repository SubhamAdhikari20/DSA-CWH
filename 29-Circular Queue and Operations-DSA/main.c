#include <stdio.h>
#include <stdlib.h>

struct circular_queue
{
    int size;
    int front_index;    // stores indixes        
    int back_index;     // stores indixes
    int *arr;
};

int isEmpty(struct circular_queue *ptr){
    if (ptr->front_index == ptr->back_index)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct circular_queue *ptr){
    if ((ptr->back_index+1) % (ptr->size) == ptr->front_index)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct circular_queue *ptr, int value){
    if (!isFull(ptr))
    { 
        ptr->back_index = (ptr->back_index+1)%(ptr->size);
        ptr->arr[ptr->back_index] = value;
        printf("Enqueued element: %d\n", value);
    }
    else
    {
        printf("QueueOverflow!!! Cannot enqueue element: %d\n", value);
    } 
}

int dequeue(struct circular_queue *ptr){
    if (!isEmpty(ptr))
    { 
        int dequeued_value;
        ptr->front_index = (ptr->front_index+1)%(ptr->size);
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
    struct circular_queue *q;
    q->size = 8;
    q->front_index = 0;
    q->back_index = 0;
    q->arr = (int *) malloc(q->size*sizeof(int));

    printf("Before enqueue, Empty?: %d\n", isEmpty(q));
    printf("Before enqueue, Full?: %d\n", isFull(q));
    
    enqueue(q, 84);
    enqueue(q, 78);
    enqueue(q, 56);
    enqueue(q, 11);
    enqueue(q, 23);
    enqueue(q, 45);
    enqueue(q, 37);    // ---> 7 elements so, circular queue is FULL because one index "0" is left blank for the "first_index" and "back_index" index trackers
    // enqueue(q, 8);    
    // enqueue(q, 12);
    // enqueue(q, 24);
    printf("After enqueue, Empty?: %d\n", isEmpty(q));
    printf("After enqueue, Full?: %d\n", isFull(q));
    printf("\n");

    printf("Before dequeue, Empty?: %d\n", isEmpty(q));
    printf("Before dequeue, Full?: %d\n", isFull(q));

    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    printf("Dequeued %d from the queue\n", dequeue(q));
    // printf("Dequeued %d from the queue\n", dequeue(q));
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
