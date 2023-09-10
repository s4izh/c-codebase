#include <stdio.h>
#include "stack.h"

static int stack_test()
{
    int ret;
    stack* st = stack_init(5);

    stack_push(st, 2);
    stack_push(st, 3);
    stack_push(st, 4);
    stack_pop(st);

    ret = stack_peek(st);
    if (ret == 3) {
        printf("Stack push peek pop test passed\n");
    } else {
        printf("Stack push peek pop test FAILED\n");
    }
    stack_push(st, 4);
    stack_push(st, 4);
    stack_push(st, 4);
    ret = stack_push(st, 4);
    if (ret < 0) {
        printf("Stack push overflow passed\n");
    } else {
        printf("Stack push overflow FAILED\n");
    }
    ret = stack_full(st);
    if (ret) {
        printf("Stack full passed\n");
    } else {
        printf("Stack full FAILED\n");
    }

    stack* st2 = stack_init(1);
    stack_push(st2, 2);
    stack_pop(st2);
    ret = stack_empty(st2);
    if (ret) {
        printf("Stack empty passed\n");
    } else {
        printf("Stack empty FAILED\n");
    }

    stack_free(st);
    stack_free(st2);
    return 0;
}

static int red_black_tree_test()
{
    return 0;
}

int main ()
{
    stack_test();
}
