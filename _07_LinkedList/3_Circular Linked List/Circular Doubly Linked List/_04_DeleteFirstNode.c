#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* addToEmpty(int data){
    struct node* p = (struct node *)malloc(sizeof(struct node));
    p->prev=p;
    p->data=data;
    p->next=p;
    return p;
}

void llTraversal(struct node *head){
    struct node *p = head;
    while (p->next != head){
        printf("Element : %d\n", p->data);
        p = p->next;
    }
    printf("Element : %d\n", p->data);
}

struct node *DeleteFirstNode(struct node *head){
    struct node *p = head;
    p->next->prev=p->prev;
    p->prev->next=p->next;
    head=p->next;
    free(p);
    p=NULL;
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
    head = DeleteFirstNode(head);
    llTraversal(head);
    return 0;
}