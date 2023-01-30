#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

/*

int countNoOfElements(struct node* head){
    struct node* tail = head;
    while(tail->next!=head){
        tail=tail->next;
    }
    // printf("%d\n", tail->data);
    struct node* p = head;
    int cnt = 1;
    while(p!=tail){
        cnt++;
        p=p->next;
    }
    return cnt;
}

*/

int countNoOfElements(struct node* head){
    struct node* p = head;
    int cnt = 1;
    while(p->next!=head){
        cnt++;
        p=p->next;
    }
    return cnt;
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

    printf("Numbers of Elements in given Circular Singly Linked List is : ");
    int x = countNoOfElements(head);
    printf("%d\n", x);

    return 0;
}