// The procedure of adding two numbers using Linked List is divided into 3 parts:
    // 1. Represent n-digit number using a singly linked list
    // 2. Reverese the numbers for addition
    // 3. Add the numbers and store the result in resultant singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* ReverseNodes(struct node* head){
    if(head==NULL){
        return head;
    }
    struct node* curr = NULL;
    struct node* nx = head->next;
    head->next = NULL;
    while(nx!=NULL){
        curr = nx;
        nx = nx->next;
        curr->next=head;
        head=curr;
    }
    return head;
}

struct node* addNode(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next=NULL;

    ptr->next = head;
    head = ptr;
    return head;
}

struct node* intToLinkedList(int n){
    struct node* p = NULL;
    while(n!=0){
        p = addNode(p, n%10);
        n/=10;
    }
    return p;
}

void LLTraversal(struct node* head){
    struct node* p = head;
    if(head==NULL){
        printf("No number");
    }
    else{
        while(p->next!=NULL){
            printf("%d", p->data);
            p=p->next;
        }
        printf("%d\n", p->data);
    }
}

struct node* AddNumbers(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* ptr3 = NULL;
    int sum=0;
    int carry = 0;
    while(ptr1 || ptr2){
        sum=0;
        if(ptr1!=NULL){
            sum+=ptr1->data;
        }
        if(ptr2!=NULL){
            sum+=ptr2->data;
        }
        sum += carry;
        carry = sum/10;
        sum =  sum%10;
        ptr3 = addNode(ptr3, sum);
        if(ptr1!=NULL){
            ptr1=ptr1->next;
        }
        if(ptr2!=NULL){
            ptr2=ptr2->next;
        }
    }
    if(carry){
        ptr3 = addNode(ptr3, carry);
    }
    return ptr3;
}

int back2Num(struct node* head){
    int n=0;
    struct node* p = head;
    while(p){
        n = n*10 + p->data;
        p=p->next;
    }
    return n;
}

int main(){
    int n1, n2;
    printf("Enter n1 : ");
    scanf("%d", &n1);
    printf("Enter n2 : ");
    scanf("%d", &n2);
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    head1 = intToLinkedList(n1);
    head2 = intToLinkedList(n2);
    printf("Before reversing:\n");
    LLTraversal(head1);
    LLTraversal(head2);
    printf("After reversing:\n");
    head1 = ReverseNodes(head1);
    head2 = ReverseNodes(head2);
    LLTraversal(head1);
    LLTraversal(head2);
    struct node* head3 = NULL;
    head3 = AddNumbers(head1, head2);
    printf("After addition  : \n");
    LLTraversal(head3);
    printf("Number in int is : ")
    int x = back2Num(head3);
    printf("%d\n", x);
    return 0;
}