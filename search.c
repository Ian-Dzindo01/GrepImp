#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void search(const char* dir_path, const char* pattern, int case_insensitive,
    int inverted_match, int line_numbers, int count_lines, int match_words) {

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

        // check whether it's a directory
        if (stat(full_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
            // skip current directory (.) and parent directory (..)
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                search(full_path, pattern, case_insensitive, inverted_match, line_numbers, count_lines, match_words);
            }
        }
        else {
            grep(full_path, pattern, case_insensitive, inverted_match, line_numbers, count_lines, match_words);
        }
    }

    closedir(dir);
}