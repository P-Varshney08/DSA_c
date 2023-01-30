#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* DeleteLastNode(struct node* head){
    if(head==NULL)
        return head;
    struct node* tail = head;
    while(tail->next->next!=head){
        tail=tail->next;
    }
    // printf("%d\n", tail->data);
    free(tail->next);
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

    first->data = 603;
    first->next = second;

    second->data = 79;
    second->next = head;

    printf("Before deleting Circular Signly Linked List is : ");
    llTraversal(head);
    head = DeleteLastNode(head);
    head = DeleteLastNode(head);
    printf("After deleting Circular Signly Linked List is : ");
    llTraversal(head);

    return 0;
}