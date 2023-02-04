#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void llTraversal(struct node *head){
    struct node *p = head;
    while (p->next != head){
        printf("Element : %d\n", p->data);
        p = p->next;
    }
    printf("Element : %d\n", p->data);
}

struct node *DeleteLastNode(struct node *head){
    struct node *tail = head->prev;
    struct node *q = tail->prev;
    head->prev=q;
    q->next=tail->next;
    free(tail);
    tail=NULL;
    return head;
}

int main(){
    struct node* head = (struct node *)malloc(sizeof(struct node));
    struct node* tail = (struct node *)malloc(sizeof(struct node));

    head->prev = tail;
    head->data=25;
    head->next=tail;

    tail->prev = head;
    tail->data=56;
    tail->next=head;
    
    // head = addToEmpty(25);
    printf("Before :\n");
    llTraversal(head);
    printf("After :\n");
    head = DeleteLastNode(head);
    llTraversal(head);
    return 0;
}