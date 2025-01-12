#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Usage: ./%s <pattern> <filetosearch>", argv[0]);
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

	if (strcmp(pattern, "") == 0 ) {
		char line[256];
		while (fgets(line, sizeof(line), file)) {
			printf("%s", line);
		}
	}

	fclose(file);
	return 0;
}