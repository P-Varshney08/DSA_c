#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void LL_Traversal(struct node* head){
    struct node* p = head;
    while(p!=NULL){
        printf("%d\n", p->data);
        p=p->next;
    }
}

void InsertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    struct node* p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    struct node* first = (struct node*)malloc(sizeof(struct node));
    head->next = first;
    first->data = 2;
    first->next = NULL;

    LL_Traversal(head);
    InsertAtEnd(head, 45);
    LL_Traversal(head);

    return 0;
}