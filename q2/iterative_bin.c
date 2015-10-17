#include <string.h>
#include "iterative_bin.h"

char smallest_character(char str[], char c)
{
    int i = 0;
    int length = strlen(str) - 1;
    int mid;
    char smallest = str[0];

    while (i <= length) {
        mid = i + (length-i) / 2;
        if (str[mid] > c) {
            smallest = str[mid];
            length = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return smallest;
}
