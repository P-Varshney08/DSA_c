#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* InsertAtPos(struct node* head, int data, int pos){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    ptr->data = data;
    pos=pos-1;
    while(pos!=1){
        p=p->next;
        pos--;
    }
    ptr->prev = p;
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    return head;

}

void llTraversal(struct node* head){
    struct node* p = head;
    while(p!=NULL){
        printf("%d\n", p->data);
        p=p->next;
    }
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 8;
    head->next = first;

    first->prev = head;
    first->data = 10;
    first->next = second;

    second->prev = first;
    second->data = 2003;
    second->next = NULL;

    // llTraversal(head);
    head = InsertAtPos(head, 4, 2);
    // llTraversal(head);
    // head = InsertAtPos(head, 12, 1);
    llTraversal(head);

    return 0;
}