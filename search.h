#pragma once

void search(const char* dir_path, const char* pattern, int case_insensitive,
            int inverted_match, int line_numbers, int count_lines, int match_words,
            int files_only, int skip_binary);

