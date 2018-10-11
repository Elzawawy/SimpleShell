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