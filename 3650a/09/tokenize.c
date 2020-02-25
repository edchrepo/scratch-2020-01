
// Kinds of tokens:
//  - Numbers (one or more digits)
//  - Operators (not digits)
//
// Whitespace isn't tokens.

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "tokenize.h"

char*
read_number(const char* text, long ii)
{
    int nn = 0;
    while (isdigit(text[ii + nn])) {
        ++nn;
    }

    char* num = malloc(nn + 1);
    memcpy(num, text + ii, nn);
    num[nn] = 0;
    return num;
}

char*
read_command(const char* line, long ii)
{
    int nn = 0;
    while (isalpha(line[ii + nn])) {
        ++nn;
    }

    char* comnd = malloc(nn + 1);
    memcpy(comnd, line + ii, nn);
    comnd[nn] = 0;
    return comnd;
}

list*
tokenize(const char* text)
{
    list* xs;

    long nn = strlen(text);
    long ii = 0;
    while (ii < nn) {
        if (isspace(text[ii])) {
            ++ii;
            continue;
        }

        if (isalpha(text[ii])) {
            char* comnd = read_command(text, ii);
            xs = cons(comnd, xs);
            ii += strlen(comnd);
            free(comnd);
            continue;
        }
        if (isdigit(text[ii])) {
            char* num = read_number(text, ii);
            xs = cons(num, xs);
            ii += strlen(num);
            free(num);
            continue;
        }

        char op[] = "";
        op[0] = text[ii];
        xs = cons(op, xs);
        ++ii;
    }

    return rev_free(xs);
}
