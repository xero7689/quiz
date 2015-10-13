#include <stdio.h>
#include <time.h>
#include <assert.h>

#include IMPL
#include TIMER

#define STR "abcdefghijklmnopqrstuvwxyz"
#define FINDCHAR 'n'

int main(void)
{
    char smallest;
    printf("String: %s\n", STR);
    struct timespec start, end;
    double cpu_time;

    assert(smallest_character(STR, FINDCHAR) == 'o');
    clock_gettime(CLOCK_REALTIME, &start);
    smallest = smallest_character(STR, FINDCHAR);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_milisecond(&start, &end);
    printf("Input: %c, Smallest: %c\n", FINDCHAR, smallest);
    printf("Time exec: %lf\n", cpu_time);

    return 0;
}
