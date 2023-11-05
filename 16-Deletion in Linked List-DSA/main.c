#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d  ", ptr -> data);
        ptr = ptr -> next; 
    }   
}

struct Node * deletion_at_beginning(struct Node *head){
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

struct Node * deletion_in_between(struct Node *head, int index){
    struct Node *ptr = head;
    int i = 0;
    if (index == 0){
        head = head -> next;
        free(ptr);
    }
    else{
        while (i != index-1)
        {
            ptr = ptr -> next;
            i++;
        }
        struct Node *q = ptr -> next;
        ptr -> next = q -> next;
        free(q);
    }
    return head;
}

struct Node * deletion_at_end(struct Node *head){
    struct Node *ptr = head;
    struct Node *q = head -> next;
    while (q -> next != NULL)
    {
        q = q -> next;
        ptr = ptr -> next;
    }
    ptr -> next = NULL;
    free(q);
    return head;
}

struct Node * deletion_of_node_with_given_value(struct Node *head, int value){
    struct Node *ptr = head;
    struct Node *q = head -> next;
    if (ptr -> data == value){
        head = head -> next;
        free(ptr);
    }
    else{
        while (q -> data != value && q -> next != NULL)
        {
            q = q -> next;
            ptr = ptr -> next;
        }
        if (q -> data == value){
            ptr -> next = q -> next;
            free(q);
        }
        else{
            printf("The data is not found\n");
        }
    }
    return head;
}

int main(){
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *) malloc(sizeof(struct Node));

    head -> data = 4;
    head -> next = second;
    
    second -> data = 9;
    second -> next = third;
    
    third -> data = 17;
    third -> next = fourth;
    
    fourth -> data = 29;
    fourth -> next = fifth;
    
    fifth -> data = 77;
    fifth -> next = NULL;
    
    printf("Linked List before deletion:\n");
    linked_list_traversal(head);
    printf("\n");
    printf("Linked List after deletion:\n");
    
    // Deletion at the beginning
    // head = deletion_at_beginning(head);
    // linked_list_traversal(head);
    
    // Deletion in between
    // head = deletion_in_between(head, 3);
    // linked_list_traversal(head);
    
    // Deletion at the end
    // head = deletion_at_end(head);
    // linked_list_traversal(head);
    
    // Deletion at given node of given value
    head = deletion_of_node_with_given_value(head, 4);
    linked_list_traversal(head);
    return 0;
}