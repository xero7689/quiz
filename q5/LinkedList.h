#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _LINKED_LIST_NODE {
    int key;
    struct _LINKED_LIST_NODE *next;
} ListNode;

ListNode *initNode(int key);
ListNode *insert(ListNode *head, ListNode *node);
ListNode *quizList(void);

#endif
