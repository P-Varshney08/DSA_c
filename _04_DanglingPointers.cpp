// A Dangling Pointer is a pointer which points to some non-existing memory location

#include <iostream>

int main(){
    int* ptr = (int*)malloc(sizeof(int));

    free(ptr);      // memory is released but ptr is a dangling pointer as ptr is not re-initialized
    ptr = NULL;
    return 0;
}

// Solution is re-initialize the pointer to NULL

#include <iostream>

int* fun(){
    int num = 10;       // here, num is local variable and gets vanished after the execution of the function which means memory has been deallocated
    return &num;
}

int main(){
    int* ptr = NULL;
    ptr = fun();
    printf("%d", *ptr);
    return 0;
}

// Segmentation Fault