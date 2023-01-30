#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

// For this we need the address of the last node of the list
// bcoz we have to update the link part of the last node so that it can point to the new node
// In order to take the address of the last node, we have to traverse the whole list

struct node* InsertAtBeginning(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    struct node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = ptr;
    return ptr;
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
    head = InsertAtBeginning(head, 23);
    head = InsertAtBeginning(head, 59);
    printf("After inserting Circulat Signly Linked List is : ");
    llTraversal(head);
    return 0;
}