#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;                // data
    struct Node *previous;       // address of previous node
    struct Node *next;       // address of next node
};

void doubly_linked_list_traversal(struct Node *head){
    struct Node *ptr = head;
    while (ptr -> next != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr -> data);

    printf("\nReverse:\n");

    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->previous;
    }
    
}

struct Node * doubly_linked_list_beginning(struct Node *head, int value){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = value;
    ptr -> previous = NULL;
    ptr -> next = head; 
    head = ptr;
    return head;
}

struct Node * doubly_linked_list_between_index(struct Node *head, int value, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = value;
    struct Node *p = head;
    if (index == 0){
        // ptr -> data = value;
        ptr -> previous = NULL;
        ptr -> next = head; 
        head = ptr;
    }
    else{
        int i = 0;
        while (i != index-1){
            p = p -> next;
            i++;
        }
        ptr -> next = p->next;
        p -> next = ptr;
        // ptr -> data = value;
    }
    return head;
}
struct Node * doubly_linked_list_end(struct Node *head, int value){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = value;
    struct Node *p = head;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

struct Node * doubly_linked_list_after_node(struct Node *head, struct Node *node, int d){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = d;
    struct Node *p = head;
    while (p != node)
    {
        p = p -> next;
    }
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes (linked list) in heap and returns a null pointer
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Linked head to second and head to NULL nodes
    head -> data = 7;
    head -> previous = NULL;
    head -> next = second;
    // Linked second to third and second to head nodes
    second -> data = 14;
    second -> previous = head;
    second -> next = third;
    // Linked third to forth and third to second nodes
    third -> data = 21;
    third -> previous = second;
    third -> next = fourth;
    // Linked fourth to fifth and fourth to third nodes
    fourth -> data = 28;
    fourth -> previous = third;
    fourth -> next = fifth;
    // Linked fifth to NULL and fifth to fourth nodes
    fifth -> data = 35;
    fifth -> previous = fourth;
    fifth -> next = NULL;

    printf("Doubly Linked List traversal before insertion:\n");
    doubly_linked_list_traversal(head);
    printf("\n");
    printf("Doubly Linked List traversal after insertion:\n");

    // Insertion at the beginning in doubly linked list
    // head = doubly_linked_list_beginning(head, 2);
    // doubly_linked_list_traversal(head);
    
    // Insertion at the index or between in circular linked list
    // head = doubly_linked_list_between_index(head, 19, 4);
    // doubly_linked_list_traversal(head);
    
    // Insertion at end in doubly linked list
    // head = doubly_linked_list_end(head, 77);
    // doubly_linked_list_traversal(head);
    
    // Insertion at end in doubly linked list
    // head = doubly_linked_list_after_node(head, head, 4);
    // doubly_linked_list_traversal(head);
    return 0;

    // Arrow operator is used by a pointer to access the members of structure
}