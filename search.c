#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

void list_directory(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name); 
    }

    closedir(dir);
}