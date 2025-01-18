#include <stdio.h>
#include <string.h>
#include "grep.h"
#include "utils.h" 

void grep(const char* filename, const char* pattern, int case_insensitive, int inverted_match, 
          int line_numbers, int count_lines, int match_words, int filenames_only, int skip_binary) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    int lineNumber = 0;
    int lineCount = 0;
    int fileMatch = 0;

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
                        fileMatch = 1;
                        break;
                    }
                }
                else {
                    if (strcmp(word, pattern) == 0) {
                        fileMatch = 1;
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
                    fileMatch = 1;
                }
            }
            else {
                if (strstr(line, pattern) != NULL) {
                    match = 1;
                    fileMatch = 1;
                }
            }
        }

        if (inverted_match) {
            match = !match;
        }

        if (match) {
            if (filenames_only) {
                printf("Pattern found in %s", filename);
                break;
            }
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

    if (count_lines && !filenames_only) {
        printf("%d", lineCount);
    }

    if (!fileMatch)
    {
        printf("No match was found\n");
    }

    printf("\n");
    fclose(file);
}