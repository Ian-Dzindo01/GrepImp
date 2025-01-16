#include <stdio.h>
#include <string.h>
#include "grep.h"

int main(int argc, char* argv[]) {
    int case_insensitive = 0;
    int inverted_match = 0;
    int line_numbers = 0;

    const char* pattern = "name";
    const char* filename = "test/test.txt";

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
        }
        else if (pattern == NULL) {
            pattern = argv[i];
        }
        else {
            filename = argv[i];
        }
    }

    printf("Flags:\n");
    printf("  Case Insensitive (-i): %d\n", case_insensitive);
    printf("  Inverted Match (-v): %d\n", inverted_match);
    printf("  Line Numbers (-n): %d\n", line_numbers);
    printf("\n");

    printf("Pattern: %s\n", pattern ? pattern : "(null)");
    printf("Filename: %s\n", filename ? filename : "(null)");

    grep(filename, pattern, case_insensitive, inverted_match, line_numbers);

    return 0;
}