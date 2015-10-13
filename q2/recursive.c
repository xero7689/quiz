#include <string.h>
#include "recursive.h"

char smallest_character(char str[], char c)
{
    int offset = 0;
    return smallest_character_recursive(str, c, offset);
}

char smallest_character_recursive(char str[], char c, int offset)
{   
    if (*str == '\0')
        return *(str - offset);
    if (*str > c)
        return *str;
    else
        return smallest_character_recursive(str+1, c, offset+1);
}

