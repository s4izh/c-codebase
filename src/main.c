#include <stdio.h>

#include "stack.h"
#include "quicksort.h"
#include "vector.h"

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

static int quicksort_test()
{
    int a[10] = {0, 2, 3, 7, 8, 4, 0, 7, 11, 9};
    quicksort(a, 10);

    int a_expected[10] = {0, 0, 2, 3, 4, 7, 7, 8, 9, 11};

    int failed = 0;

    for (int i = 0; i < 10 && !failed; ++i) {
        if (a[i] != a_expected[i]) {
            failed = 1;
        }
    }

    if (failed) {
        printf("Quicksort test 1 FAILED, result = \n");
        for (int i = 0; i < 10; ++i)
            printf("%d ", a[i]);
        printf("\n");
    }
    else
        printf("Quicksort test 1 passed\n");

    int b[10] = {17, 2, 42, 7, 8, 4, 0, 7, 11, 9};
    quicksort(b, 10);

    int b_expected[10] = {0, 2, 4, 7, 7, 8, 9, 11, 17, 42};

    if (failed) {
        printf("Quicksort test 2 FAILED, result = \n");
        for (int i = 0; i < 10; ++i)
            printf("%d ", b[i]);
        printf("\n");
    }
    else
        printf("Quicksort test 2 passed\n");

    return 0;
}

static void vector_debug(vector* v)
{
    fprintf(stderr, "length: %d\n", v->length);
    fprintf(stderr, "capacity: %d\n", v->capacity);
    fprintf(stderr, "data: ");
    int *data = v->data;
    fprintf(stderr, "[ ");
    for (int i = 0; i < v->length; ++i)
        fprintf(stderr, "%d ", data[i]);
    fprintf(stderr, "]\n");
}

static void vector_test()
{
    vector v;
    vector_init(&v, sizeof(int));
    vector_push_back(&v, (void *)&(int){1});

    if (v.length == 1 && v.capacity == 2 && ((int*)v.data)[0] == 1) {
        printf("Vector push_back test 1 passed\n");
    } else {
        printf("Vector push_back test 1 FAILED\n");
        vector_debug(&v);
    }

    vector_push_back(&v, (void *)&(int){2});
    vector_push_back(&v, (void *)&(int){3});

    if (v.length == 3 && v.capacity == 4 && ((int*)v.data)[2] == 3) {
        printf("Vector push_back test 2 passed\n");
    } else {
        printf("Vector push_back test 2 FAILED\n");
        vector_debug(&v);
    }
}

int main ()
{
    stack_test();
    quicksort_test();
    vector_test();
    return 0;
}
