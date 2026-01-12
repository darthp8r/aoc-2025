#include <aoc2025.h>


static size_t
zeroes(const list_t *data)
{
  register const list_t *node = NULL;

  register long long int combination = 0;
  register long long int position = 50;
  register long long int turn = 0;

  for (node = data; node; node = node->next) {
    position += node->u.z;
    position %= 100;
    if (!position) {
      combination++;
    }
  }

  return combination;
}


static size_t
clicks(const list_t *data)
{
  register const list_t *node = NULL;

  register long long int combination = 0;
  register long long int position = 50;
  register long long int landing = 0;
  register long long int turn = 0;

  for (node = data; node; node = node->next) {
    turn = node->u.z;
    if (turn < 0) {
      combination -= turn / 100;
    }
    else {
      combination += turn / 100;
    }
    landing = position + (turn % 100);

    if (landing < 0) {
      if (position) {
        combination++;
      }
      position = landing + 100;
    }
    else if (!landing) {
      combination++;
      position = landing;
    }
    else if (landing < 100) {
      position = landing;
    }
    else {
      combination++;
      position = landing - 100;
    }
  }

  return combination;
}


/*  redefine each line to be an integer number, negative for left
    turns, positive for right ones */
static list_t *
transform(list_t *data)
{
  register list_t *node = NULL;
  register char direction = 0;

  long long int turn = 0;

  for (node = data; node; node = node->next) {
    direction = node->u.str.text[0];
    sscanf(1+node->u.str.text, "%lld", &turn);
    free(node->u.str.text);

    switch (direction) {
    case 'L':
      node->u.z = -turn;
      break;
    case 'R':
      node->u.z = turn;
      break;
    default:
      node->u.z = 0;
      break;
    }
  }

  return data;
}

aoc_t *
secret_entrance(list_t *data)
{
  aoc_t me = {
    .part1 = zeroes,
    .part2 = clicks,
    .data = transform(data),
  };

  return memdup((void*) &me, sizeof(me));
}

