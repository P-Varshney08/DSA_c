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

struct node* InsertNode(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;
    while(p->next!=NULL && p->next->data<data){
        p=p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    struct node* first = (struct node*)malloc(sizeof(struct node));
    head->next = first;
    first->data = 20;
    first->next = NULL;

    LL_Traversal(head);
    head = InsertNode(head, 15);
    LL_Traversal(head);

    return 0;
}