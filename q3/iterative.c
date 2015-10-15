#include <stdlib.h>
#include "iterative.h"

static inline void swapNode(node* p)
{
    node* tmp;
    tmp = p->left;
    p->left = p->right;
    p->right = tmp;
}

node *flatten(node* root)
{
    if (!root) return NULL;

    node *tmp = root;

    while (tmp != NULL) {
        if (tmp->left != NULL) {
            if (tmp->right != NULL) {
                node *next = tmp->left;
                while (next->right != NULL)
                    next = next->right;
                next->right = tmp->right;
            }
            tmp->right = tmp->left;
            tmp->left = NULL;
        }
        tmp = tmp->right;
    }
    return tmp;
}

