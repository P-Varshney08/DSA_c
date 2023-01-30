#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* DeleteFirstNode(struct node* head){
    if(head==NULL)
        return head;
    struct node* tail = head;
    while(tail->next!=head){
        tail=tail->next;
    }
    // printf("%d\n", tail->data);
    struct node* p = head->next;
    free(head);
    head = p;
    tail->next=head;
    return head;
}

void llTraversal(struct node* head){
    struct node* p = head;
    if(head!=NULL){
        do{
            printf("%d ", p->data);
            p=p->next;
        }while(p!=head);

    }
    printf("\n");
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    head->data = 8;
    head->next = first;

    first->data = 10;
    first->next = second;

    second->data = 2003;
    second->next = head;

    printf("Before deleting Circular Signly Linked List is : ");
    llTraversal(head);
    head = DeleteFirstNode(head);
    printf("After deleting Circular Signly Linked List is : ");
    llTraversal(head);

    return 0;
}