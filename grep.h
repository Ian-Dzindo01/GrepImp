#pragma once
#ifndef GREP_H
#define GREP_H

void grep(const char* filename, const char* pattern, int case_insensitive, int inverted_match, int line_numbers, int count_lines);

#endif 