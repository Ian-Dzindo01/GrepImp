#include <ctype.h>
#include <string.h>

const char* strcasestr(const char* haystack, const char* needle) {
    if (!*needle) return haystack;

    while (*haystack) {
        const char* h = haystack;
        const char* n = needle;

        while (*h && *n && tolower((unsigned char)*h) == tolower((unsigned char)*n)) {
            h++;
            n++;
        }

        if (!*n) return haystack;

        haystack++; 
    }

    return NULL; 
}