#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include IMPL
#include TIMER

#define SORTED_ARRAY_SIZE 2600000
#define SORTED_TXT "sorted.txt"

int main(void)
{
    FILE *fp;
    char sorted[SORTED_ARRAY_SIZE];
    char smallest;
    struct timespec start, end;
    double cpu_time;
    char randChar;
    fp = fopen(SORTED_TXT, "r");
    if (fp == NULL) {
        printf("Cannot open the file.\n");
        return -1;
    }
    fgets(sorted, sizeof(sorted), fp);
    fclose(fp);
    srand(time(NULL));

    assert(smallest_character("cfjpv", 'a') == 'c');
    assert(smallest_character("cfjpv", 'e') == 'f');
    assert(smallest_character("cfjpv", 'z') == 'c');

    randChar = 'a' + (random() % 26);
    clock_gettime(CLOCK_REALTIME, &start);
    smallest = smallest_character(sorted, randChar);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_milisecond(&start, &end);
    printf("Input: %c, Smallest: %c\n", randChar, smallest);
    printf("Time exec: %lfms\n", cpu_time);


    return 0;
}
