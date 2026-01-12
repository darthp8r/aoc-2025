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


aoc_t *
gift_shop(const list_t *data)
{
  aoc_t noo = {
    .part1 = mirrored,
    .part2 = repeated,
    .data = data,
  };

  return memdup((void*) &noo, sizeof(noo));
}

