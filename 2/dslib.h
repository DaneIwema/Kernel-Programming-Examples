#include <stdlib.h>

struct stack
{
    int number; // the number of integer values currently stored in the stack
    int *data; /* this pointer will be initialized inside stack_init(). Also, the actual size of
    the allocated memory will be determined by “capacity’ value that is given as one of the
    parameters to stack_init()*/
    int total_num; // the total number of integer values that can be stored in this stack
};
typedef struct stack stack_t;

void init_stack(stack_t *s, int capacity);

int size_stack(stack_t *s);

int pop_stack(stack_t *s);

void push_stack(stack_t *s, int e);

void deallocate_stack(stack_t *s);