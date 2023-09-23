#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h>

typedef struct vector {
    void *data;
    int length;
    int capacity;
    size_t data_size;
} vector;

void vector_init(vector* v, size_t data_size);

void vector_push_back(vector* v, void* data);

void vector_pop_back(vector* v);

#endif /* __VECTOR_H__ */
