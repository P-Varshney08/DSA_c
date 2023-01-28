// A Doubly Linked List is different from a Singly linked list in a way that each node has an extra pointer that points to the previous node together with the next pointer and data similar to singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* InsertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    struct node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    return head;
}

// struct node* InsertAtEnd(struct node* head, int data){
//     struct node* ptr = (struct node*)malloc(sizeof(struct node));
//     struct node* p = head;
//     ptr->data = data;
//     while(p->next!=NULL){
//         p=p->next;
//     }
//     ptr->prev = p;
//     p->next = ptr;
//     ptr->next = NULL;
//     return head;
// }

void llTraversal(struct node*  head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node* head = malloc(sizeof(struct node));
    struct node* first = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 8;
    head->next = first;

    first->prev = head;
    first->data = 18;
    first->next = NULL;

    head = InsertAtEnd(head, 78);
    llTraversal(head);
    head = InsertAtEnd(head, 80);
    // llTraversal(head);
    // head = InsertAtEnd(head, 8);
    llTraversal(head);

    return 0;
}