#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include TIMER
#include LL
#include IMPL

int main(void)
{
    struct timespec start, end;
    double cpu_time;

    ListNode *head;
    head = quizList();
#if defined(__GNUC__)
    __builtin___clear_cache((char *) head, (char *) head + sizeof(ListNode *));
#endif

    // Testing
    clock_gettime(CLOCK_REALTIME, &start);
    ListNode *entry = detectCycle(head);
    clock_gettime(CLOCK_REALTIME, &end);

    assert(entry->key == 2);
    cpu_time = diff_in_milisecond(&start, &end);

    printf("Entry at: %d, %p\n", entry->key, entry);
    printf("Exec time: %lf\n", cpu_time);
    return 0;
}
