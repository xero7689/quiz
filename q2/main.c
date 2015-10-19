#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NDEBUG
#include <assert.h>

#include IMPL
#include TIMER

int main(int argc, char *argv[])
{
    if (argc == 0) perror("Please input a sorted string for searching!\n");
    
    char *string = argv[1];
    char findChar = *argv[2];

    FILE *output;
    char *fn;
    int sl = strlen(string);
    if (!asprintf(&fn, "%s_%d.txt", argv[0], sl)) perror("Unable to create file name.\n");
    output = fopen(fn, "a+");

    char smallest;
    struct timespec start, end;
    double cpu_time;
    
    assert(smallest_character("cfjpv", 'a') == 'c');
    assert(smallest_character("cfjpv", 'e') == 'f');
    assert(smallest_character("cfjpv", 'z') == 'c');

    clock_gettime(CLOCK_REALTIME, &start);
    smallest = smallest_character(string, findChar);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_milisecond(&start, &end);
    printf("String=%s\n", string);
    printf("Input: %c, Smallest: %c\n", findChar, smallest);
    printf("Time exec: %lfms\n", cpu_time);
    
    fprintf(output, "%lf\n", cpu_time);
    fclose(output);

    return 0;
}
