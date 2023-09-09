#ifndef __tree_map_h__
#define __tree_map_h__

#include <stdlib.h>

typedef struct {
    int key;
    void* value;
    void* leftLeaf;
    void* rightLeaf;
} Node;

typedef struct {
    Node* root;
    size_t valueSize;
} Tree;

void* createTreeMap();

#endif /* __tree_map_h__ */
