#include <stdio.h>
#include <string.h>
#include "grep.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    int case_insensitive = 0;
    int inverted_match = 0;
    int line_numbers = 0;
    int count_lines = 0;
    int match_words = 0;
    int recursive_search = 1;
    int filenames_only = 1;

    const char* pattern = "name";
    const char* filename = "test";

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (strstr(argv[i], "i")) {
                case_insensitive = 1;
            }
            if (strstr(argv[i], "v")) {
                inverted_match = 1;
            }
            if (strstr(argv[i], "n")) {
                line_numbers = 1;
            }
            if (strstr(argv[i], "c")) {
                count_lines = 1;
            }
            if (strstr(argv[i], "w")) {
                match_words = 1;
            }
            if (strstr(argv[i], "r")) {
                recursive_search = 1;
            }
            if (strstr(argv[i], "l")) {
                filenames_only = 1;
            }
        }

        else if (pattern == NULL) {
            pattern = argv[i];
        }
        else {
            filename = argv[i];
        }
    }

    printf("Flags:\n");
    printf("  Case Insensitive    (-i): %d\n", case_insensitive);
    printf("  Inverted Match      (-v): %d\n", inverted_match);
    printf("  Line Numbers        (-n): %d\n", line_numbers);
    printf("  Count Lines         (-c): %d\n", count_lines);
    printf("  Match Word          (-w): %d\n", match_words);
    printf("  Recursive Search    (-r): %d\n", recursive_search);
    printf("  Filenames Only          (-l): %d\n", filenames_only);
    printf("\n");

    printf("Pattern: %s\n", pattern ? pattern : "(null)");
    printf("Filename: %s\n", filename ? filename : "(null)");

    if (recursive_search) {
        search(filename, pattern, case_insensitive, inverted_match, line_numbers, count_lines, match_words, filenames_only);
    }
    else {
        grep(filename, pattern, case_insensitive, inverted_match, line_numbers, count_lines, match_words, filenames_only);
    }

    return 0;
}