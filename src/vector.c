#include "vector.h"
#include <stdlib.h>
#include <string.h>

void vector_init(vector* v, size_t data_size)
{
    v->data = malloc(2 * data_size);
    v->length = 0;
    v->capacity = 2;
    v->data_size = data_size;
}

void vector_push_back(vector* v, void* data)
{
    if (v->length == v->capacity)
    {
        v->capacity *= 2;
        void *new = realloc(v->data, v->capacity * v->data_size);
        memcpy(v->data, new, v->capacity * v->data_size);;
        v->data = new;
        memcpy(v->data + v->length * v->data_size, data, v->data_size);
    }
    else {
        memcpy(v->data + v->length * v->data_size, data, v->data_size);
    }
    v->length++;
}

void vector_pop_back(vector* v)
{
    if (v->length > 0)
    {
        v->length--;
    }
}

void* vector_get_value(vector* v, int index)
{
    if (index >= v->length)
        return NULL;
    return v->data + index * v->data_size;
}
