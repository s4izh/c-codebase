#include "red-black-tree.h"

Tree* initTree(int key, void* value, size_t valueSize)
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
    tree->valueSize = valueSize;

    root->value = value;
    root->leftLeaf = NULL;
    root->rightLeaf = NULL;

    return tree;
}

Node* initNode(int key, void* value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
        return NULL;

    node->key = key;
    node->value = value;
    node->leftLeaf = NULL;
    node->rightLeaf = NULL;

    return node;
}

int insert(Tree* tree, int key, void* value)
{
    return insert_rec(tree->root, key, value);
}

int insert_rec(Node* node, int key, void* value)
{
    if (key <= node->key) {
        if (node->leftLeaf == NULL) {
            Node* newNode = initNode(key, value);
            if (newNode == NULL)
                return -1;
            node->leftLeaf = newNode;
            return 0;
        }
        else
            insert_rec(node->leftLeaf, key, value);
    }
    if (key <= node->key) {
        if (node->rightLeaf == NULL) {
            Node* newNode = initNode(key, value);
            if (newNode == NULL)
                return -1;
            node->rightLeaf = newNode;
            return 0;
        }
        else
            insert_rec(node->rightLeaf, key, value);
    }
}
