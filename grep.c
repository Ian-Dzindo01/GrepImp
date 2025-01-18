#include <stdio.h>
#include <string.h>
#include "grep.h"
#include "utils.h" 

void grep(const char* filename, const char* pattern, int case_insensitive, int inverted_match, int line_numbers, int count_lines, int match_words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    int lineNumber = 0;
    int lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        int match = 0;

        char line_copy[256];
        strcpy_s(line_copy, sizeof(line_copy), line); // copy original line for tokenization

        if (match_words) {
            char* context;
            char* word = strtok_s(line_copy, " \t\n", &context);

            while (word != NULL) {
                if (case_insensitive) {
                    if (_stricmp(word, pattern) == 0) {
                        match = 1;
                        break;
                    }
                }
                else {
                    if (strcmp(word, pattern) == 0) {
                        match = 1;
                        break;
                    }
                }

                word = strtok_s(NULL, " \t\n", &context);
            }
        }
        else {
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
        }

        if (inverted_match) {
            match = !match;
        }

        if (match) {
            lineCount++;
            if (!count_lines) {
                if (line_numbers) {
                    printf("Line %d: %s", lineNumber, line);
                }
                else {
                    printf("%s", line);
                }
            }
        }
    }

    if (count_lines) {
        printf("%d", lineCount);
    }

    printf("\n");
    fclose(file);
}
