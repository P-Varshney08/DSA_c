// Singly Linked List is a list made up of nodes that consists of two parts : Data and Node

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void count_nodes(struct node* head){
    struct node* p = head;
    int cnt = 0;
    if(head==NULL){
        printf("Linked List is empty");
    }
    while(p!=NULL){
        cnt++;
        p=p->next;
    }
    printf("%d", cnt);
}

int main(){
    struct node* head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));

    head->data = 8;
    head->next = first;

    first->data = 10;
    first->next = second;

    second->data = 2003;
    second->next = NULL;

    count_nodes(head);

    return 0;
}
