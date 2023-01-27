// NULL pointer is a pointer that doesn't point to any memory location
// It represents an invalid memory location

// When a NULL pointer is assigned to a pointer, then the pointer is considered as NULL pointer

// Uses :
    // It is used to initialize a pointer when that pointer ins't assigned any valid memory address yet

    // Example : 
    #include <iostream>

    int main(){
        int* p = NULL;

        return 0;
    }


    // Useful for handling errors when using malloc function

    // Example : 
    #include <iostream>

    int main(){
        int* p;
        p = (int*)malloc(2*(sizeof(int)));
        if(ptr==NULL)
            printf("Memory could not be allocated");
        else
            printf("Memory allocated successfully");

        return 0;
    }

// the value of NULL is 0. we can either use NULL or 0 but this 0 is written in context of pointers and is not equivalent to integer 0.
// Example :

#include <iostream>

int main(){
    int* ptr = NULL;
    printf("%d", *ptr);
    return 0;
}

// Output : 0

// size of NULL pointer depends upon the platform and is similar to size of the normal pointers

// Example :

#include <iostream>

int main(){
    printf("%d", sizeof(NULL));
    return 0;
}
// output : 4

// it is a good practice to initialize a pointer with NULL