#include <stdlib.h>
#include "iterative.h"

ListNode *detectCycle(ListNode *head)
{
    ListNode *first = head;
    ListNode *second = head;

    while (first != NULL && second != NULL) {
        first = first->next;
        second = second->next;
        if (second != NULL)
            second = second->next;
        if (first == second)
            break;
    }

    if (second == NULL) return NULL;

    first = head;
    while (first != second) {
        first = first->next;
        second = second->next;
    }
    return second;
}
