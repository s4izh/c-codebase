#include "sergio/vector.h"
#include <stdlib.h>
#include <string.h>

int vector_alloc(vector* v, size_t data_size)
{
    v->length = 0;
    v->capacity = 2;
    v->data_size = data_size;
    v->data = malloc(2 * data_size);
    if (v->data == NULL)
        return -1;
    return 0;
}

void vector_free(vector* v)
{
    free(v->data);
}

int vector_push_back(vector* v, void* data)
{
    if (v->length == v->capacity) {
        v->capacity *= 2;
        void *new = realloc(v->data, v->capacity * v->data_size);
        if (new == NULL)
            return -1;
        v->data = new;
    }
    memcpy(v->data + v->length * v->data_size, data, v->data_size);
    v->length++;
    return 0;
}

int vector_pop_back(vector* v)
{
    if (v->length > 0) {
        v->length--;
    }
    if (v->length < v->capacity / 2) {
        v->capacity = v->capacity / 2;
        void *new = realloc(v->data, v->capacity * v->data_size);
        if (new == NULL)
            return -1;
        v->data = new;
    }
    return 0;
}

void* vector_get_value(vector* v, int index)
{
    if (index >= v->length)
        return NULL;
    return v->data + index * v->data_size;
}

void vector_for_each(vector* v, void(*f)(void*))
{
    void* curr_data = v->data;
    for (int i = 0; i < v->length; ++i) {
        f(curr_data);
        curr_data += v->data_size;
    }
}

#define for_each(element, v) \
    element = *(v->data); \
    for (size_t i = 0; i < v->length; element = *((v->data)+(v->data_size * i++)))
