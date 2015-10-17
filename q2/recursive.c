#include <assert.h>
#include <string.h>
#include "recursive.h"

static char sc_recursive(char str[], char c, unsigned int offset)
{
    unsigned int k = offset + 1;
    assert((((offset^k) & (1^k)) > 0) && "Integer Overflow.\n");

    if (*str == '\0')
        return *(str - offset);
    if (*str > c)
        return *str;
    return sc_recursive(str+1, c, offset+1);
}


char smallest_character(char str[], char c)
{
    unsigned int offset = 0;
    return sc_recursive(str, c, offset);
}


