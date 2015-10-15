#ifndef BST_H
#define BST_H

typedef struct _TREE_NODE {
    int data;
    struct _TREE_NODE *left;
    struct _TREE_NODE *right;
} node;

node *create_node(void);
void create_tree(node *root);
void traversal_postOrder(node *p);
void traversal_quizRequire(node *p);
#endif

