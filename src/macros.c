#include <stdio.h>
#include "macros.h"

#define Slice_Protoype(type)\
    typedef struct type##_slice {\
        type *ptr; \
        u32 length; \
    } type##_slice; \
    \
    type##_slice type##_slice_subslice(type##_slice *slice, u32 start, u32 end);\
    type type##_slice_index(type##_slice *slice, usize idx);

#define Slice_Impl(type)\
    type##_slice type##_slice_subslice(type##_slice *slice, u32 start, u32 end) {\
        return (type##_slice) { slice->ptr + start, end - start };\
    }\
    type type##_slice_index(type##_slice *slice, usize idx) {\
        if (idx >= slice->length) {\
            return (type) {0};\
        }\
        return slice->ptr[idx];\
    }

Slice_Protoype(int)
Slice_Impl(int)

Slice_Protoype(i8)
Slice_Impl(i8)

int main () {
    printf("hello world\n");
    int_slice slice = { (int[]){1, 2, 3, 4, 5}, 5 };
}
