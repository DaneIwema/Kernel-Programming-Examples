#include "dslib.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    stack_t test_stack;

    init_stack(&test_stack, 7);
    printf("Initialized a stack of size 7\n");

    printf("Pushing 15, 22, 5, 10, 9, 36, 84, 72, 53\n");

    push_stack(&test_stack, 15);
    push_stack(&test_stack, 22);
    push_stack(&test_stack, 5);
    push_stack(&test_stack, 10);
    push_stack(&test_stack, 9);
    push_stack(&test_stack, 36);
    push_stack(&test_stack, 84);
    push_stack(&test_stack, 72);
    push_stack(&test_stack, 53);

    printf("Current stack size: %d\n", size_stack(&test_stack));

    // pop values
    while (size_stack(&test_stack) != 0) {
        printf("popped %d\n", pop_stack(&test_stack));
    }

    printf("extra pop on an empty stack returns: %d\n", pop_stack(&test_stack));

    printf("Final stack size: %d\n", size_stack(&test_stack));

    // free memory
    deallocate_stack(&test_stack);

    return 0;
}