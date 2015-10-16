#include <stdlib.h>

#include "recursive.h"

// Find the junction of cycle of linked list recursively.
static ListNode *findJunc(ListNode *first, ListNode *second)
{
    if (first == NULL && second == NULL)
        return NULL; // No cycle

    first = first->next;
    second = second->next;
    if (second != NULL)
        second = second->next;

    if (first == second)
        return first;

    return findJunc(first, second);
}

// Given a linked list, return the node where the cycle begins.
// if there is no cycle, return null.
ListNode *detectCycle(ListNode *head)
{
    ListNode *first = head;
    ListNode *second = head;

    second = findJunc(first, second);
    if (second == NULL) return NULL;

    first = head;

    // Move to junction
    while (first != second) {
        first = first->next;
        second = second->next;
    }

    return second;
}
