#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX_SAMPLE_SIZE 1024

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

int is_binary_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    unsigned char buffer[MAX_SAMPLE_SIZE];
    size_t bytes_read = fread(buffer, 1, MAX_SAMPLE_SIZE, file);

    int is_binary = 0;

    for (size_t i = 0; i < bytes_read; ++i) {
        if (!isprint(buffer[i]) && !isspace(buffer[i])) {
            // allow common UTF-8 multibyte characters
            if (buffer[i] >= 0x80) {
                continue;
            }
            is_binary = 1;
            break;
        }
    }

    fclose(file);
    return is_binary;
}




