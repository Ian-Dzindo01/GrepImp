#include <stdio.h>
#include <string.h>
#include "grep.h"
#include "utils.h" 

void grep(const char* filename, const char* pattern, int case_insensitive, int inverted_match, int line_numbers) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    int lineNumber = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        int match = 0;
        if (case_insensitive) {
            if (strcasestr(line, pattern) != NULL) {
                match = 1;
            }
        }
        else {
            if (strstr(line, pattern) != NULL) {
                match = 1;
            }
        }

        if (inverted_match) {
            match = !match;
        }

        if (match) {
            if (line_numbers) {
                printf("Line %d: %s", lineNumber, line);
            }
            else {
                printf("%s", line);
            }
        }
    }

    fclose(file);
}
