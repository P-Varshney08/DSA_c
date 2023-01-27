// It is a pointer which has no associated data type with It
// It can point to any data of any data type and can be typecasted to any type

#include <iostream>

int main(){
    int n = 10;
    void* p = &n;

    printf("%d", *(int*)p);
    return 0;
}
// We cannot dereference a void pointer
// malloc and calloc function returns a void pointer
// Due to this reason they can allocate a memory for any type of data