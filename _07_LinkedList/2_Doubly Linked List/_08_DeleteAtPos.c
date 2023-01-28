#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void llTraversal(struct node* head){
    struct node* p = head;
    while(p!=NULL){
        printf("%d\n", p->data);
        p=p->next;
    }
}
struct node* DeleteFirstNode(struct node* head){
    struct node* p = head->next;
    p->prev = NULL;
    free(head);
    return p;
}
struct node* DeleteLastNode(struct node* head){
    struct node* p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->prev->next = NULL;
    free(p);
    return head;
}

struct node* DeleteAtPos(struct node* head, int pos){
    struct node* p = head;
    if(pos==1){
        head = DeleteFirstNode(head);
        return head;
    }
    pos = pos-1;
    while(pos!=1){
        p=p->next;
        pos--;
    }
    if(p->next==NULL){
        head = DeleteLastNode(head);
    }
    else{
        struct node* q = p->next;
        p->next = q->next;
        q->next->prev = p;
        free(q);
    }
    return head;
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    head->prev=NULL;
    head->data=1;
    head->next = second;
    
    second->prev=head;
    second->data=43;
    second->next = third;

    third->prev=second;
    third->data=21;
    third->next = fourth;

    fourth->prev=third;
    fourth->data=67;
    fourth->next = NULL;

    llTraversal(head);
    head = DeleteAtPos(head, 2);
    llTraversal(head);
    
    return 0;
}