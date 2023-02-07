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
            printf("(%.1fx^%d)", p->coefficient, p->exponent);
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
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
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

void MultiplyPolynomials(struct node* head1,struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            head3 = InsertInList(head3, ptr1->coefficient*ptr2->coefficient, ptr1->exponent+ptr2->exponent);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        ptr2=head2;
    }    
    printf("Multiplied polynomial before Simplification is : ");
    printPolynomial(head3);

    struct node* ptr3 = head3;
    struct node* temp = NULL;
    while(ptr3->next!=NULL){
        if(ptr3->exponent==ptr3->next->exponent){
            ptr3->coefficient =  ptr3->coefficient+ptr3->next->coefficient;
            temp=ptr3->next;
            ptr3->next=ptr3->next->next;
            free(temp);
        }
        else{
            ptr3=ptr3->next;
        }
    }
    printf("Multiplied polynomial before Simplification is : ");
    printPolynomial(head3);
}

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("Enter first polynomial : \n");
    head1=create(head1);
    printf("Enter second polynomial : \n");
    head2=create(head2);
    struct node* head3=NULL;
    MultiplyPolynomials(head1, head2);
    
    return 0;
}