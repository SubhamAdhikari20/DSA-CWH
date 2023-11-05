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

struct Node * insert_at_beginning(struct Node *head, int d){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = d;
    head = ptr;
    return ptr;
}

struct Node * insert_at_between(struct Node *node, int d){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> next = node -> next;
    node -> next = ptr;
    ptr -> data = d;
    return ptr;
}

struct Node * insert_at_index(struct Node *head, int d, int index){
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

struct Node * insert_at_end(struct Node *head, int d){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = d;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    return head;
}

struct Node * insert_after_node(struct Node *head, struct Node *node, int d){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = d;
    ptr -> next = node -> next;
    node -> next = ptr;
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
    fourth -> next = NULL;

    printf("Linked List before insertion\n");
    linked_list_traversal(head);
    printf("\n");
    // printf("%d", head);
    printf("Linked List after insertion\n");

    // Insert at the Beginning
    // head = insert_at_beginning(head, 121);
    // linked_list_traversal(head);
    
    // Insert in between
    // head = insert_at_between(second, 77);
    // linked_list_traversal(head);
    
    // Insert at index
    // head = insert_at_index(head, 77, 2);
    // linked_list_traversal(head);

    // Insert at the end
    // head = insert_at_end(head, 99);
    // linked_list_traversal(head);
    
    // Insert at after a node
    head = insert_after_node(head, third, 99);
    linked_list_traversal(head);

    return 0;

    // Arrow operator is used by a pointer to access the members of structure
}