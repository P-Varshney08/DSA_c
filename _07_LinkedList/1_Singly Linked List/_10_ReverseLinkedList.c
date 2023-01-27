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

struct node* ReverseLinkedList(struct node* head){
    struct node* prev = NULL;
    struct node* next = NULL;
    while(head!=NULL){
        next=head->next;
        head->next=prev;
        prev=head;
        head = next;
    }
    head = prev;
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
    head = ReverseLinkedList(head);
    LL_Traversal(head);

    return 0;
}