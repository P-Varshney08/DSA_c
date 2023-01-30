// There are two types of Circular Linked list:
//     1. Circular Singly Linked List
//     2. Circular Doubly Linked List

// Circular Singly Linked List is similar to Singly Linked List except that the last node of the Circular Singly Linked List points to the first node
// Circular Doubly Linked List is similar to Doubly Linked List except that the last node of the Circular Doubly Linked List points to the first node andfirst node of the Circular Doubly Linked List points to the last node

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* circularSingly(int data){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->next = head;
    return head;
}

int main(){
    int data;
    scanf("%d", &data);
    struct node* head = circularSingly(data);
    printf("%d\n", head->data);
    return 0;
}