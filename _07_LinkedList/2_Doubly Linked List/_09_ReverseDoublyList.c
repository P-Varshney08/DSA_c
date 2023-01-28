#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void llTraversal(struct node* head){
    struct node* p = head;
    while(p!=NULL){
        printf("%d\n", p->data);
        p=p->next;
    }
}
struct node* reverseList(struct node* head){
    struct node* ptr1 = head;
    struct node* ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2!=NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1=ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    head->prev=NULL;
    head->data=1;
    head->next = second;
    
    second->prev=head;
    second->data=43;
    second->next = third;

    third->prev=second;
    third->data=21;
    third->next = fourth;

    fourth->prev=third;
    fourth->data=67;
    fourth->next = NULL;

    llTraversal(head);
    head = reverseList(head);
    llTraversal(head);
    return 0;
}