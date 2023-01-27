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

void DeletionAtPos(struct node* head, int pos){
    struct node* curr = head;
    struct node* prev = head;
    if(head==NULL){
        printf("List is already empty");
    }
    else if(pos==1){
        free(head);
        head = NULL;
    }
    else{
        while(pos!=1){
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        free(curr);
        curr = NULL;
    }
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
    DeletionAtPos(head, 1);
    LL_Traversal(head);
    
    return 0;
}