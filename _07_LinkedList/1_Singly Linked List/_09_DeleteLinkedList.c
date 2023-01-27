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

struct node* DeleteLinkedList(struct node* head){
    struct node* p = head;
    while(p!=NULL){
        p=p->next;
        free(head);
       head = p;
    }
    return head;
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    
    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;
    
    second->data = 5;
    second->next = NULL;

    LL_Traversal(head);
    head = DeleteLinkedList(head);
    LL_Traversal(head);

    return 0;
}