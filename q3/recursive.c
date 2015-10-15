#include <stdlib.h>
#include "recursive.h"

static inline void swapNode(node* p)
{
    node* tmp;
    tmp = p->left;
    p->left = p->right;
    p->right = tmp;
}

node *flatten(node *p)
{
    if (!p) return NULL;
    if (p->left == NULL && p->right == NULL)
        return p;

    node *tmp = NULL;

    if (p->left) {
        swapNode(p);
        flatten(p->left);
    }
    if (p->right)
        tmp = flatten(p->right);

    tmp->right = p->left;
    return p->left;
}
