#include "stack.h"

stack *stack_init(int size) {
    stack *s = (stack *) malloc(sizeof(stack));
    s->data = (int *) malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

int stack_push(stack *s, int data) {
    if (stack_full(s)) {
        return -1;
    }
    s->data[++s->top] = data;
    return 0;
}

int stack_pop(stack *s) {
    if (stack_empty(s)) {
        return -1;
    }
    return s->data[s->top--];
}

int stack_peek(stack *s) {
    if (stack_empty(s)) {
        return -1;
    }
    return s->data[s->top];
}

int stack_full(stack *s) {
    return s->top == s->size - 1;
}

int stack_empty(stack *s) {
    return s->top == -1;
}

void stack_free(stack *s) {
    free(s->data);
    free(s);
}
