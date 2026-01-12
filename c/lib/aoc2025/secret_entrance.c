#include <aoc2025.h>


static size_t
zeroes(const list_t *data)
{
  return 0;
}


static size_t
clicks(const list_t *data)
{
  return 0;
}


aoc_t *
secret_entrance(const list_t *data)
{
  aoc_t noo = {
    .part1 = zeroes,
    .part2 = clicks,
    .data = data,
  };

  return memdup((void*) &noo, sizeof(noo));
}

