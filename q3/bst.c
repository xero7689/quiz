#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

node *create_node(void)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void create_tree(node *root)
{
    // Create a binary tree, according to question 3
    root->data = 1;

    root->left = create_node();
    root->left->data = 2;
    root->left->left = create_node();
    root->left->left->data = 3;
    root->left->right = create_node();
    root->left->right->data = 4;
    root->right = create_node();
    root->right->data = 5;
    root->right->right = create_node();
    root->right->right->data = 6;
}

/* Post Order Traversal */
void traversal_postOrder(node *p)
{
    if (!p) return;
    printf("%d", p->data);
    traversal_postOrder(p->left);
    traversal_postOrder(p->right);
}

/* Question 3 only traverse right child node.*/
void traversal_quizRequire(node *p)
{
    if(!p) return;
    printf("%d", p->data);
    traversal_quizRequire(p->right);
}
