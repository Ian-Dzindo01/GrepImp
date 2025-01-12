#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Usage: ./main.exe <pattern> <filetosearch>", argv[0]);
		return 1;
	}

	const char* pattern = argv[1];
	const char* filetosearch = argv[2];

	printf("%s\n", pattern);        
	printf("%s\n", filetosearch);  

	FILE* file = fopen(filetosearch, "r");

	if (file == NULL) {
		perror("Error opening file");
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
				printf("Line %d: %s", lineNumber, line);
			}
		}
	}
		
	fclose(file);
	return 0;
}