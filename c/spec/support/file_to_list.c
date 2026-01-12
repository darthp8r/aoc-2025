#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <aoc2025.h>

#include "file_to_list.h"


/** because reading a line one at a time is a joy for higher-level languages */
static size_t
next_line(FILE *fp, char *text, size_t limit)
{
  register size_t i = 0;
  register char   c = 0;

  for (i = 0; i < limit; i++) {
    if ((c = fgetc(fp)) == '\n') {
      text[i] = '\0';
      break;
    }
    else if (feof(fp)) {
      text[i-1] = '\0';
      break;
    }
    else {
      text[i] = c;
    }
  }

  return i;
}


/** make a node out of the next line, then do it again

  'register' may or may not consume stack, but you know they won't be modified elsewhere
  'static' gets clobbered each time in to avoid consuming stack on recursion
*/
static list_t *
line_by_line(FILE *fp)
{
  register size_t length = 0;
  register list_t *next = NULL;

  static char text[1024];

  /*  dropping this empty line */
  if ((length = next_line(fp, text, 1024)) < 1) {
//  printf("[%s] [%lu] SKIPPING [%d]\n", text, length, feof(fp));
    return feof(fp) ? NULL : line_by_line(fp);
  }

  /*  malloc(1) failed on node */
  else if ((next = malloc(sizeof(list_t))) == NULL) {
    return NULL;
  }

  /*  malloc(1) failed on content */
  else if ((next->u.str.text = malloc(1+length)) == NULL) {
    free(next);
    return NULL;
  }

  /*  copy content and progress to the next line */
  else {
//  printf("[%s] [%lu]\n", text, length);
    strcpy(next->u.str.text, text);
    next->u.str.strlen = length;
    next->next = line_by_line(fp);
    return next;
  }
}


/** read non-empty lines from this file into a constructed linked list
*/
list_t *
file_to_list(const char *filename)
{
  register list_t *lyst = (list_t *) NULL;
  register FILE   *fp = fopen(filename, "r");

  if (fp) {
    lyst = line_by_line(fp);
    fclose(fp);
  }

  return lyst;
}


/** not gonna provide a free_list(7) function: just leak it all on exit(1) :) */

