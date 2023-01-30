#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* DeleteAtPos(struct node* head, int pos){
    if(head==NULL){
        return head;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return head;
    }
    
    struct node* p = head;
    while(pos>2){
        p=p->next;
        pos--;
    }
    // printf("%d\n", tail->data);
    struct node* q = p->next;
    p->next = q->next;
    free(q);
    q = NULL;
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
    head = DeleteAtPos(head, 1);
    printf("After deleting Circular Signly Linked List is : ");
    llTraversal(head);

    return 0;
}