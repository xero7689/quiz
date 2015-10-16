#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

ListNode *initNode(int key)
{
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->key = key;
    new->next = NULL;
    return new;
}

ListNode *insert(ListNode *head, ListNode *node)
{
    if (!head) return NULL;
    ListNode *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    return node;
}

ListNode *quizList(void)
{
    ListNode *head = initNode(1);
    ListNode *entry = initNode(2);
    insert(head, entry);
    int i = 3;
    for (; i < 6; i++)
        insert(head, initNode(i));
    ListNode *tail = initNode(6);
    insert(head, tail);
    tail->next = entry;
    return head;
}
