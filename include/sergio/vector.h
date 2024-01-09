/**
 * @file vector.h
 * @brief Functions for working with dynamic arrays (vectors).
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h>

/**
 * @struct vector
 * @brief Structure representing a dynamic array.
 *
 * @var void* data
 * Pointer to the start of the array.
 *
 * @var int length
 * Number of elements in the array.
 *
 * @var int capacity
 * Total capacity of the array (number of elements it can hold).
 *
 * @var size_t data_size
 * Size of each element in the array, in bytes.
 */
typedef struct vector {
    void* data;
    size_t length;
    size_t capacity;
    size_t data_size;
} vector;

/**
 * @brief Allocate memory for a new dynamic array with the given size.
 *
 * The dynamic array is initialized to an empty state, with no elements and a capacity of zero.
 *
 * @param[out] v Pointer to the dynamic array to be allocated.
 * @param[in] data_size Size of each element in the array, in bytes.
 * @return 0 if successful, or -1 if there was an error allocating memory.
 */
int vector_alloc(vector* v, size_t data_size);

/**
 * @brief Free the memory associated with a dynamic array.
 *
 * The dynamic array is set to an empty state, with no elements and a capacity of zero.
 *
 * @param[in,out] v Pointer to the dynamic array to be freed.
 */
void vector_free(vector* v);

/**
 * @brief Append an element to the end of a dynamic array.
 *
 * The length of the dynamic array is increased by one.
 *
 * @param[in,out] v Pointer to the dynamic array.
 * @param[in] data Pointer to the element to be appended.
 * @return 0 if successful, or -1 if there was an error allocating memory.
 */
int vector_push_back(vector* v, void* data);

/**
 * @brief Remove the last element from a dynamic array.
 *
 * The length of the dynamic array is decreased by one.
 *
 * @param[in,out] v Pointer to the dynamic array.
 * @return 0 if successful, or -1 if there was an error allocating memory.
 */
int vector_pop_back(vector* v);

/**
 * @brief Get a pointer to the element at the specified index in a dynamic array.
 *
 * The behavior is undefined if the index is out of range.
 *
 * @param[in] v Pointer to the dynamic array.
 * @param[in] index Index of the element to get.
 * @return Pointer to the element at the specified index, or NULL if there was an error allocating
 * memory.
 */
void* vector_get_value(vector* v, size_t index);

/**
 * @brief Call a function for each element in a dynamic array.
 *
 * The behavior is undefined if the function modifies the elements of the array.
 *
 * @param[in] v Pointer to the dynamic array.
 * @param[in] f Function to be called for each element.
 */
void vector_for_each(vector* v, void (*f)(void*));

/* #define for_each(element, v) \ */
/*     for (size_t i = 0, element = *(v->data); i < v->length; element = *((v->data)+(v->data_size *
 * i++))) */

#define for_each(element, v)            \
    for (size_t i = 0; i < (v)->length; \
         ++i, (element) = (void*)((char*)((v)->data) + ((v)->data_size * i)))

#endif
