#include <string.h>
#include "recursive.h"

char smallest_character(char str[], char c)
{
    char *smallest = NULL;
    int len = 0;
    return *(recursive(str, c, smallest, len));
}


char *recursive(char *str, char input, char *smallest, int len)
{
    if(*str != '\0') {
        if (*str > input) {
            if (smallest != NULL) {
                if (*str < *smallest) {
                    smallest = str;
                }
            } else {
                smallest = str;
            }
        }
        smallest = recursive(str+1, input, smallest, len+1);
    }
    if (smallest == NULL)
        return str-len;
    else
        return smallest ;
}


