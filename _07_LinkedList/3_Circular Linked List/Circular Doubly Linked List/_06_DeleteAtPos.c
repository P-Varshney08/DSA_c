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

struct node *DeleteAtPos(struct node *head, int pos){
    struct node *p = head;
    while(pos>2){
        p=p->next;
        pos--;
    }
    struct node *q = p->next;
    p->next=q->next;
    q->next->prev=p;

    free(q);
    q=NULL;
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
    head = DeleteAtPos(head, 2);
    llTraversal(head);
    return 0;
}