#ifndef __AOC2025_SPEC_SUPPORT_FILE_TO_LIST__
#define __AOC2025_SPEC_SUPPORT_FILE_TO_LIST__

#include <aoc2025.h>

/*  gimme a filename and I'll give you a linked list of its non-empty lines */
list_t *
file_to_list(const char *filename);

#endif
