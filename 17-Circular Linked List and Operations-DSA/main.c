#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;                // data
    struct Node *next;      // address of next node
};

void circular_linked_list_traversal(struct Node *head){
    struct Node *ptr = head;
    // while (ptr -> next != head)
    // {
    //     printf("%d  ", ptr->data);
    //     ptr = ptr->next;
    // }
    // printf("%d", ptr -> data);
    do
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    // printf("%d", ptr -> data);
}

struct Node * insertion_circular_linked_list_beginning(struct Node *head, int value){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = value;
    struct Node *p = head -> next;  // At this point, "p" is pointing at the second node after head
    while (p -> next != head)
    {
        p = p -> next;
    } 
    // At this point, "p" is pointing at the last node
    ptr -> next = head; 
    p -> next = ptr;
    head = ptr;
    return head;
}

struct Node * insertion_circular_linked_list_between_index(struct Node *head, int d, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index-1){
        p = p -> next;
        i++;
    }
    ptr -> next = p->next;
    p -> next = ptr;
    ptr -> data = d;

    return head;
}
struct Node * insertion_circular_linked_list_end(struct Node *head, int d){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = d;
    struct Node *p = head;
    while (p -> next != head)
    {
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = head;
    return head;
}

struct Node * insertion_circular_linked_list_after_node(struct Node *head, struct Node *node, int d){
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
    fourth -> next = head;

    printf("Circular Linked List traversal before insertion:\n");
    circular_linked_list_traversal(head);
    printf("\n");
    printf("Circular Linked List traversal after insertion:\n");

    // Insertion at the beginning in circular linked list
    // head = insertion_circular_linked_list_beginning(head, 2);
    // circular_linked_list_traversal(head);
    
    // Insertion at the index or between in circular linked list
    // head = insertion_circular_linked_list_between_index(head, 19, 4);
    // circular_linked_list_traversal(head);
    
    // Insertion at end in circular linked list
    // head = insertion_circular_linked_list_end(head, 4);
    // circular_linked_list_traversal(head);
    
    // Insertion at end in circular linked list
    head = insertion_circular_linked_list_after_node(head, second, 4);
    circular_linked_list_traversal(head);
    return 0;

    // Arrow operator is used by a pointer to access the members of structure
}