#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* InsertAtLast(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
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
    head->data = 8;
    head->next = first;

    first->data = 10;
    first->next = head;
    printf("Before inserting Circulat Signly Linked List is : ");
    llTraversal(head);
    head = InsertAtLast(head, 23);
    head = InsertAtLast(head, 59);
    printf("After inserting Circulat Signly Linked List is : ");
    llTraversal(head);
    return 0;
}