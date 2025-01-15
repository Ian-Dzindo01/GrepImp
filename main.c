#include <stdio.h>

int main(int argc, char* argv[])
{
	int case_insensitive = 0;
	int inverted_match = 0;
	int line_numbers = 0;

	const char* pattern = NULL;
	const char* filename = NULL;

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


	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		perror("Error opening	file");
		return 1;
	}

	char line[256];
	int lineNumber = 0;

	if (strcmp(pattern, "") == 0) {
		while (fgets(line, sizeof(line), file)) {
			printf("%s", line);
		}
	}

	else {
		while (fgets(line, sizeof(line), file)) {
			lineNumber++;

			if (strstr(line, pattern) != NULL) {
				if (line_numbers)
				{
					printf("Line %d: %s", lineNumber, line);
				}
				else {
					printf("%s", line);
				};
			}
		}

		fclose(file);
		return 0;
	}
}