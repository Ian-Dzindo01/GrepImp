#pragma once
#ifndef SEARCH_H
#define SEARCH_H

void search(const char* dir_path, const char* pattern, int case_insensitive,
            int inverted_match, int line_numbers, int count_lines, int match_words,
            int files_only);

#endif 
