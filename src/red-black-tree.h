#ifndef __TREE_MAP_H__
#define __TREE_MAP_H__

#include <stdlib.h>

#define RBT_CMP(a, b) ((a > b) - (a < b))

typedef struct {
    int key;
    void* value;
    void* left_leaf;
    void* right_leaf;
} Node;

typedef struct {
    Node* root;
    size_t value_size;
    void (*cmp);
} Tree;

void* createTreeMap();
Tree* init_tree(int key, void* value, size_t value_size, void* cmp);
int insert(Tree* tree, int key, void* value);
int insert_rec(Node* node, int key, void* value);

#endif /* __TREE_MAP_H__ */
