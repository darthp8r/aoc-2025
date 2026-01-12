#ifndef __AOC2025__
#define __AOC2025__

#include <sys/types.h>

/*  linked list of non-empty lines of strings */
typedef struct list_s {
  union {
    /*  input file */
    struct {
      char    *text;
      size_t  strlen;
    } str;

    /*  challenge support: by day */
    long long int z;      /*  one integer: 01 */
    size_t        nn[2];  /*  two natural: 02 */
  } u;
  struct list_s *next;
} list_t;


/*  usage: aoc->part1(aoc->data), aoc->part2(aoc->data) */
typedef struct aoc_s {
  size_t  (*part1)(const list_t *data);
  size_t  (*part2)(const list_t *data);
  const list_t *data;
} aoc_t;


/*  print 'text' with a glow about it */
int
shine(const char *text);


/*  a familiar toy of mine, for assembling a data structure on the stack
    and then returning a clone of it from the heap */
void *
memdup(const void *source, size_t length);


/*  all the challenges */
aoc_t *secret_entrance(const list_t *data);
aoc_t *gift_shop(const list_t *data);


#endif

