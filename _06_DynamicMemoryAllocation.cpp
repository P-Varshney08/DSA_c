/*
Static Memory Allocation:

Memory allocated during compile time is called Static Memory
The memory allocated is fixed and cannot be increased or decreased during runtime
Example : int arr[5] = {1, 2, 3, 4, 5};
memory allocated at compile time and is fixed and user cannot increase or decrease the size of the array at run-time.

If the values stored by the user in the array at run time is less than the size specified, then there will be wastage of memory.

If the values stored by user in the array at run time is more than the size specified then the program may crash or misbehave.

Dynamic Memory Allocation:

The process of allocating memory at the time of execution is called dynamic memory allocation.
Heap is the segment of memory where dynamic memory allocation takes place.
Unlike stack where memory is allocated or deallocated in a defined order, heap is an area of memory where memory is allocated or deallocated without any order or randomly
There are certain built in functions that can help in allocating or deallocating some memory nspace at run time
allocated memory can only be accessed through Pointers

The process of allocating memory at the time of execution is called dynamic memory allocation

1. malloc()

malloc() is built-in function declared in the header file <stdlib.h>

malloc is short name for "memory allocation" and is used to dynamically allocate a single large block of contiguous memory according to the size specified.

Syntax - (void* )malloc(size_t size)

malloc function simply allocates a memory block according to the size specified in the heap and on success it returns a Pointer to the first byte of the allocated memory else returns NULL

size_t is defined in <stdlib.h> as unsigned int

Why Void Pointer??

malloc doesn't have an idea of what it is pointing to
It merely allocates memory requested by the user without knowing the type of data to be stored inside the memory.
Void pointer can be typecasted to an appropriate type

        int *ptr = (int*)malloc(4);

malloc allocates 4 bytes of memory in the heap and the address of the first byte is stored in the pointer ptr

*/

// Example : 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;
    printf("Enter thr number of integers: ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n*sizeof(int));

    if(ptr==NULL){
        printf("Memory not available");
        exit(1);
    }
    for(int i=0; i<n; i++){
        printf("Enter an integer: ");
        scanf("%d", ptr + i);
    }
    for(int i=0; i<n; i++){
        printf("%d ", *(ptr+i));
    }
    return 0;
}

/*
2. calloc()

calloc() function is used to dynamically allocate multiple blocks of memory.
It is diffferent from malloc() in 2 ways :
    1. calloc() needs two arguments instead of just one
        Syntax - void* calloc(no_of_blocks, size_of_each_block)

        Example :
        int* ptr = (int*)calloc(10, sizeof(int));
        equivalent malloc -
        int* ptr = (int*)malloc(10*sizeof(int));

    2. memory allocated by calloc is initialized to zero
       (memory allocated by malloc is initialized with some garbage value)

    malloc and calloc both return NULL when sufficient memory is not available in the heap
    */

/*
3. realloc()

realloc() function is used to change the size of the memory block without loosing the old data.

Syntax : void* realloc(void* ptr, size_t new_size)
Example :
int* ptr = (int *)malloc(sizeof(int));
ptr = (int*)realloc(ptr, 2*sizeof(int));


4. free()


free() function is used to release the dynamically allocated memory in heap

Syntax : void free(ptr);

The memory allocated in heap will not be released automatically after using the memory. The space remains there and can't be used.
It is the programmer's responsibility to release the memory after use.
*/