#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void list_directory(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent* entry;
    struct stat statbuf;

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        // Check whether it's a file or a directory
        if (stat(full_path, &statbuf) == 0) {  // Ensure stat() is successful
            if (S_ISDIR(statbuf.st_mode)) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { //Check that . current dir and .. parent dir are not checked
                    printf("Found subdirectory: %s\n", full_path);
                }
            }
            else {
                printf("Found file: %s\n", full_path);
            }
        }
    }

    closedir(dir);
}
