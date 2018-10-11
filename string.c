/***
 * String  Module 
 * string.c library implementation.
 * Created By : Amr Elzawawy
 * Created On : 10-10-18
 ***/

#include "string.h"

int getStringLength(char * s){
    int stringlength=0;
    while( *s != '\0')
    {
        stringlength++;
        s++;
    }
    return stringlength;
}

void appendCharToString(char *s, char c)
{
    int len = getStringLength(s);
    s[len] = c;
    s[len + 1] = '\0';
}

void removeNewLineChar(char *s)
{
    int new_line = getStringLength(s) -1;
    if (s[new_line] == '\n')
        s[new_line] = '\0';
}