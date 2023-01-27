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

struct node* DeletionLastNode(struct node* head){
    if(head==NULL){
        printf("List is already empty");
    }
    else if(head->next==NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node* p = head;
        struct node* q = p->next;
        while(q->next!=NULL){
            p = p->next;
            q = q->next;
        }
        free(q);
        q = NULL;
        p->next = NULL;
    }
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
    head = DeletionLastNode(head);
    LL_Traversal(head);
    head = DeletionLastNode(head);
    LL_Traversal(head);
    head = DeletionLastNode(head);
    LL_Traversal(head);

    return 0;
}