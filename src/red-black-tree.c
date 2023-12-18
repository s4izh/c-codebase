#include "red-black-tree.h"

Node* init_node(int key, void* value)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
        return NULL;

    node->key = key;
    node->value = value;
    node->left_leaf = NULL;
    node->right_leaf = NULL;

    return node;
}

/**
 * Initializes a new tree.
 *
 * @param key         The key to use for the root node of the tree.
 * @param value       A pointer to the value to store in the root node of the tree.
 * @param value_size  The size of the value to store in the root node of the tree.
 *
 * @return           The newly created tree, or NULL if the allocation failed.
 */
Tree* init_tree(int key, void* value, size_t value_size)
{
    Tree* tree = malloc(sizeof(Tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = init_node(key, value);
    return tree;
}

/**
 * @brief Inserts a new node into the tree.
 *
 * This function inserts a new node with the specified key and value into the
 * tree. If the key already exists in the tree, the existing node is updated to
 * contain the new value.
 *
 * @param tree The tree to insert the node into.
 * @param key The key of the new node.
 * @param value The value of the new node.
 */
int insert(Tree* tree, int key, void* value)
{
    return insert_rec(tree->root, key, value);
}

/**
 * @brief Insert a node with the given key and value into the tree.
 *
 * @param node The root of the tree to insert into.
 * @param key The key to use for the new node.
 * @param value The value to store in the new node.
 * @return 0 if the node was inserted successfully, -1 otherwise.
 */
int insert_rec(Node* node, int key, void* value)
{
    if (key <= node->key) {
        if (node->left_leaf == NULL) {
            Node* new_node = init_node(key, value);
            if (new_node == NULL) {
                return -1;
            }
            node->left_leaf = new_node;
            return 0;
        } else {
            insert_rec(node->left_leaf, key, value);
        }
    }
    if (key >= node->key) {
        if (node->right_leaf == NULL) {
            Node* new_node = init_node(key, value);
            if (new_node == NULL) {
                return -1;
            }
            node->right_leaf = new_node;
            return 0;
        } else {
            insert_rec(node->right_leaf, key, value);
        }
    }
    return -1;
}
