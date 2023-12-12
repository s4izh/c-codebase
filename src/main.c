#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#include "stack.h"
#include "quicksort.h"
#include "vector.h"

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
} LogLevel;

#if defined(__GNUC__) || defined(__clang__)
#define CHECK_PRINT_FMT(a, b) __attribute__((format(printf, a, b)))
#else
#define CHECK_PRINT_FMT(...)
#endif

CHECK_PRINT_FMT(2, 3) void my_log(LogLevel log, const char* fmt, ...)
{
    FILE* fd = stdout;
    switch (log) {
        case DEBUG:
            fprintf(fd, "DEBUG: ");
            break;
        case INFO:
            fprintf(fd, "INFO: ");
            break;
        case WARNING:
            fprintf(fd, "WARNING: ");
            break;
        case ERROR:
            fd = stderr;
            fprintf(fd, "ERROR: ");
            break;
        default:
            fprintf(fd, "UNKNOWN: ");
            break;
    }
    va_list args;
    va_start(args, fmt);
    vfprintf(fd, fmt, args);
    va_end(args);
}

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
    failed = 0;

    for (int i = 0; i < 10 && !failed; ++i) {
        if (b[i] != b_expected[i]) {
            failed = 1;
        }
    }

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

static void multiply_by_2(int* i) {
    *i *= 2;
}

static void vector_test()
{
    vector v;
    vector_alloc(&v, sizeof(int));
    vector_push_back(&v, (void *)&(int){0});

    if (v.length == 1 && v.capacity == 2 && ((int*)v.data)[0] == 0) {
        printf("Vector push_back test 1 passed\n");
    } else {
        printf("Vector push_back test 1 FAILED\n");
        vector_debug(&v);
    }

    vector_push_back(&v, (void *)&(int){1});
    vector_push_back(&v, (void *)&(int){2});

    if (v.length == 3 && v.capacity == 4 && ((int*)v.data)[2] == 2) {
        printf("Vector push_back test 2 passed\n");
    } else {
        printf("Vector push_back test 2 FAILED\n");
        vector_debug(&v);
    }
    vector_push_back(&v, (void *)&(int){3});
    vector_push_back(&v, (void *)&(int){4});
    vector_push_back(&v, (void *)&(int){5});
    vector_push_back(&v, (void *)&(int){6});
    vector_push_back(&v, (void *)&(int){7});
    vector_push_back(&v, (void *)&(int){8});
    vector_push_back(&v, (void *)&(int){9});

    if (v.length == 10 && v.capacity == 16 && ((int*)v.data)[9] == 9) {
        printf("Vector push_back test 3 passed\n");
    } else {
        printf("Vector push_back test 3 FAILED\n");
        vector_debug(&v);
    }

    int *value = vector_get_value(&v, 9);
    int *value_err = vector_get_value(&v, 10);
    if (*value == 9 && value_err == NULL) {
        printf("Vector get_value test passed\n");
    } else {
        printf("Vector get_value test FAILED\n");
    }
    vector_pop_back(&v);
    value_err = vector_get_value(&v, 9);
    if (value_err == NULL) {
        printf("Vector pop_back test 1 passed\n");
    } else {
        printf("Vector pop_back test 1 FAILED\n");
    }
    vector_pop_back(&v);
    vector_pop_back(&v);
    if (v.capacity == 8 && v.length == 7) {
        printf("Vector pop_back test 2 passed\n");
    } else {
        printf("Vector pop_back test 2 FAILED\n");
    }

    vector_for_each(&v, (void(*)(void*)) multiply_by_2);
    int for_each_failed = 0;
    for (int i = 0; i < v.length; ++i) {
        if (*(int *)vector_get_value(&v, i) != i*2)
            for_each_failed = 1;
    }
    if (!for_each_failed) {
        printf("Vector for_each passed\n");
    } else {
        printf("Vector for_each FAILED\n");
    }

    vector_free(&v);
}

int main ()
{
    int a = 10;
    my_log(INFO, "Hello world %d\n", a);
    stack_test();
    quicksort_test();
    vector_test();
    return 0;
}
