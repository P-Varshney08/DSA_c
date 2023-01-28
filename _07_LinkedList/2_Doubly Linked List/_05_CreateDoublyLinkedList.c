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
struct node* addToEmpty(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    head = ptr;
    return head;
}

struct node* InsertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    struct node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    return head;
}

struct node* createList(struct node* head){
    int n, data;
    printf("Nodes : ");
    scanf("%d", &n);
    if(n==0)
    return head;
    printf("Node 1 : ");
    scanf("%d", &data);
    head = addToEmpty(head, data);
    for(int i=1; i<n; i++){
        printf("Node %d : ", i+1);
        scanf("%d", &data);
        head = InsertAtEnd(head, data);
    }
    return head;
}
int main(){
    struct node* head = NULL;
    head = createList(head);
    llTraversal(head);
    return 0;
}