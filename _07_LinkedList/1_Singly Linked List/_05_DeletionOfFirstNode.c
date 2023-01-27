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

struct node* DeletionFirstNode(struct node* head){
    if(head==NULL)
        printf("Lint is already empty");
    else{
        struct node* ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    struct node* first = (struct node*)malloc(sizeof(struct node));
    head->next = first;
    first->data = 2;
    first->next = NULL;

    LL_Traversal(head);
    head = DeletionFirstNode(head);
    LL_Traversal(head);

    return 0;
}