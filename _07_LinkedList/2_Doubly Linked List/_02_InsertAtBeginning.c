// A Doubly Linked List is different from a Singly linked list in a way that each node has an extra pointer that points to the previous node together with the next pointer and data similar to singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addToEmpty(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    head = ptr;
    return head;
}


struct node* InsertAtBeginning(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void llTraversal(struct node*  head){
    struct node* temp = head;
    while(temp->next!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node* head = NULL;
    // struct node* head = malloc(sizeof(struct node));
    // head->prev = NULL;
    // head->data = 8;
    // head->next = NULL;

    head = addToEmpty(head, 78);
    // llTraversal(head);
    head = InsertAtBeginning(head, 89);
    // llTraversal(head);
    head = InsertAtBeginning(head, 02);
    llTraversal(head);

    return 0;
}