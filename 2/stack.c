//Created by Dane Iwema

#include "dslib.h"

void init_stack(stack_t *s, int capacity) {
    s->total_num = capacity;
    s->data = malloc(sizeof(int)*capacity);
    s->number = 0;
}

int size_stack(stack_t *s) {
    return s->number;
}

int pop_stack(stack_t *s) {
    if (s->number == 0) {
        return -9999; // or handle error differently
    }
    s->number--;
    return s->data[s->number];
}

void push_stack(stack_t *s, int e) {
    if (s->number < s->total_num) {
        s->data[s->number] = e;
        s->number++;
    }
}

void deallocate_stack(stack_t *s) {
    free(s->data);
    s->data = NULL;
    s->number = 0;
    s->total_num = 0;
}