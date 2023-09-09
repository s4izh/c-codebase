#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>

typedef struct stack {
    int *data;
    int top;
    int size;
} stack;

stack *stack_init(int size);

void stack_push(stack *s, int data);

int stack_pop(stack *s);

int stack_peek(stack *s);

int stack_full(stack *s);

int stack_empty(stack *s);

void stack_free(stack *s);

#endif /* __STACK_H__ */
