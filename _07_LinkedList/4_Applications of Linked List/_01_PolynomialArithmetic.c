#include <stdio.h>
#include <stdlib.h>

struct node{
    float coefficient;
    int exponent;
    struct node* next;
};

void printPolynomial(struct node* head){
    if(head==NULL){
        printf("No term in the polynomial\n");
    }
    else{
        struct node* p = head;
        while(p!=NULL){
            printf("%.1fx^%d", p->coefficient, p->exponent);
            p=p->next;
            if(p!=NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}

struct node* InsertInList(struct node* head, float coeff, int expo){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->coefficient = coeff;
    ptr->exponent = expo;
    ptr->next = NULL;
    if(head==NULL || expo > head->exponent){
        ptr->next = head;
        head=ptr;
    }
    else{
        struct node* temp = head;
        while(temp->next!=NULL && expo<temp->next->exponent){
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next=ptr;
    }
    return head;
}

struct node* create(struct node* head){
    int n;
    float coeff;
    int expo;
    printf("Enter number of terms : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter Coefficient for %d term : ", i+1);
        scanf("%f", &coeff);
        printf("Enter Exponent for %d term : ", i+1);
        scanf("%d", &expo);
        head = InsertInList(head, coeff, expo);
    }
    return head;
}
// Simply creating a linked list without any order is not a good option when target is to perform some arithmetic operations.
// Polynomial expression should be sorted in descending order of their exponents
// So for representing polynomial expression, we will use a sorted linked list which would be in descending order based on the exponents

int main(){
    struct node* head = NULL;
    // printf("Enter the polynomial");
    head=create(head);
    printPolynomial(head);
    return 0;
}