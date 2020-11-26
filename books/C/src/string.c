#include <stdio.h>

char * 
strcpy(char * dst, const char * src)
{
    while(*src != '\0')
        *(dst++) = *(src++);
    *dst = '\0';
    return dst;
}

size_t 
strlen(const char * str)
{
    size_t count = 0;
    while(*(str++) != '\0')
        count++;
    return count;
}

char * 
strcat(char * destination, char * source)
{
    char *dst = destination;
    char *src = source;
    while(*(++dst) != '\0')
        ;
    while(*src != '\0')
        *(dst++) = *(src++);

    *dst = '\0';
    

    return destination;
}

char *
strcat(char *dest, const char *src)
{
    size_t i,j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}

