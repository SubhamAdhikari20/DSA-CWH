#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;                // data
    struct Node *next;      // address of next node
};

void linked_list_traversal(struct Node *ptr){
    // ptr = (struct Node*) malloc(sizeof(struct Node));
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes (linked list) in heap and returns a null pointer
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Linked head to second nodes
    head -> data = 7;
    head -> next = second;
    // Linked second to third nodes
    second -> data = 14;
    second -> next = third;
    // Linked third to forth nodes
    third -> data = 21;
    third -> next = fourth;
    // Linked head to second nodes
    fourth -> data = 28;
    fourth -> next = NULL;

    linked_list_traversal(head);
    return 0;

    // Arrow operator is used by a pointer to access the members of structure
}