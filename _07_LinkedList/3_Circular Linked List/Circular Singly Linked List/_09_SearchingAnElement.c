#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int SearchingAnElement(struct node* head, int el){
    int idx = 0;
    struct node* p = head;
    do{
        if(p->data == el){
            return idx;
        }
        p=p->next;
        idx++;
    }while (p!=head);

    return -1;
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

    printf("Enter the element you want to find index of : ");
    int el;
    scanf("%d", &el);
    int idx = SearchingAnElement(head, el);
    printf("%d\n", idx);

    return 0;
}