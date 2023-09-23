#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h>

typedef struct vector {
    void *data;
    int length;
    int capacity;
    size_t data_size;
} vector;

int vector_alloc(vector* v, size_t data_size);

void vector_free(vector* v);

int vector_push_back(vector* v, void* data);

int vector_pop_back(vector* v);

void* vector_get_value(vector* v, int index);

void vector_for_each(vector* v, void(*f)(void*));

#endif /* __VECTOR_H__ */
