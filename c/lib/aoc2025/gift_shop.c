#include <aoc2025.h>


static size_t
mirrored(const list_t *data)
{
  return 0;
}


static size_t
repeated(const list_t *data)
{
  return 0;
}

/*  extract each comma-separated range from one line of text */
static list_t *
transform(list_t *data)
{
  return data;
}


aoc_t *
gift_shop(list_t *data)
{
  aoc_t me = {
    .part1 = mirrored,
    .part2 = repeated,
    .data = transform(data),
  };

  for (register const list_t *node = me.data; node; node = node->next) {
    printf("(%lu %lu)\n", node->u.nn[0], node->u.nn[1]);
  }

  return memdup((void*) &me, sizeof(me));
}

