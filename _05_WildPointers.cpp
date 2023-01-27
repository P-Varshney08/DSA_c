// also k/as uninitialized pointers
// These pointers usually point to some arbitary memory location and may cause a program to crash or misbehave.
// Example :
#include <iostream>

int main(){
    int* ptr;
    *p = 10;
    return 0;
}

// to avoid Wild Pointers : 
    // 1. Initialize them with the address of a known variable

    #include <iostream>

    int main(){
        int var = 10;
        int* ptr;
        *p = &var;      // no more a wild pointer
        return 0;
    }

    // 2. Explicitly allocate tehh memory and put the values in the allocated memory

    #include <iostream>

    int main(){
        int* p = (int*)malloc(sizeof(int));
        *p = 10;
        free(p);
        return 0;
    }
