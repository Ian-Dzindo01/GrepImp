#pragma once

void grep(const char* filename, const char* pattern, int case_insensitive, 
		  int inverted_match, int line_numbers, int count_lines, int match_words, int filenames_only,
		  int skip_binary);

