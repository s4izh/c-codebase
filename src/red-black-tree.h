#ifndef __TREE_MAP_H__
#define __TREE_MAP_H__

#include <stdlib.h>

#define RBT_CMP(a, b) ((a > b) - (a < b))

typedef enum { RED, BLACK } Color;

typedef struct {
    int key;
    void* value;
    void* left_leaf;
    void* right_leaf;
    Color color;
} Node;

typedef struct {
    Node* root;
    size_t value_size;
} Tree;

void* createTreeMap();
Tree* init_tree(int key, void* value, size_t value_size);
int insert(Tree* tree, int key, void* value);
int insert_rec(Node* node, int key, void* value);

#endif /* __TREE_MAP_H__ */
