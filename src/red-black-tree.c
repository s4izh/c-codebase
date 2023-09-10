#include "red-black-tree.h"

Tree* init_tree(int key, void* value, size_t value_size, void* cmp)
{
    Tree* tree = malloc(sizeof(Tree));
    if (tree == NULL) {
        return NULL;
    }

    Node *root = malloc(sizeof(Node));
    if (root == NULL) {
        return NULL;
    }

    tree->root = root;
    tree->value_size = value_size;

    root->value = value;
    root->left_leaf = NULL;
    root->right_leaf = NULL;

    return tree;
}

Node* init_node(int key, void* value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
        return NULL;

    node->key = key;
    node->value = value;
    node->left_leaf = NULL;
    node->right_leaf = NULL;

    return node;
}

int insert(Tree* tree, int key, void* value)
{
    return insert_rec(tree->root, key, value);
}

int insert_rec(Node* node, int key, void* value)
{
    if (key <= node->key) {
        if (node->left_leaf == NULL) {
            Node* new_node = init_node(key, value);
            if (new_node == NULL)
                return -1;
            node->left_leaf = new_node;
            return 0;
        }
        else
            insert_rec(node->left_leaf, key, value);
    }
    if (key >= node->key) {
        if (node->right_leaf == NULL) {
            Node* new_node = init_node(key, value);
            if (new_node == NULL)
                return -1;
            node->right_leaf = new_node;
            return 0;
        }
        else
            insert_rec(node->right_leaf, key, value);
    }
    return -1;
}
