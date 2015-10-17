#include <string.h>
#include "iterative.h"

char smallest_character(char str[], char c)
{
    char *smallest = NULL;
    int len = strlen(str);
    int i = 0;

    for( ; i < len ; i++) {
        if (str[i] > c) {
            if (smallest == NULL)
                smallest = &str[i];
            else if (*smallest > str[i])
                smallest = &str[i];
        }
    }

    if (smallest == NULL)
        return str[0];
    else return *smallest;
}


