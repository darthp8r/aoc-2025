#include <string.h>

#include <aoc2025.h>


/*  one plus 'n' zeroes */
/*  static */
size_t
pow10int(size_t n)
{
  register size_t exp = 0;
  register size_t m = 1;

  for (exp = 0; exp < n; exp++) {
    m *= 10;
  }

  return m;
}

/*  how many digits in this base-10 'n' */
/*  static */
size_t
dig10int(size_t n)
{
  register size_t digits = 0;
  register size_t m = 1;

  for (digits = 1; digits < 12; digits++) {
    if (n < (10*m)) {
      return digits;
    }
    else {
      m *= 10;
    }
  }

  return (size_t) -1;
}

/*  promote each lower bound to its first mirror (if needed),
    then add the appropriate increment until it's no longer less
    than the upper bound */
static size_t
mirror(size_t lower, size_t upper)
{
  static size_t increments[6] = {
    11,       /*  2   11, 22, 33, 44 */
    101,      /*  4   2323, 2424, 2525 */
    1001,     /*  6   304304, 305305, 306306 */
    10001,    /*  8   45064506, 45074507, 45084508 */
    100001,   /*  10  5600756007, 5600856008, 5600956009 */
    1000001,  /*  12  670009670009, 670010670010, 670011670011  (not achieved)*/
  };

  register size_t magnitude = 0;  /*  power-of-ten containing lower/upper */
  register size_t zeroes = 0;     /*  number of zeroes betwixt the ones */
  register size_t hi = 0;         /*  higher half of digits */
  register size_t lo = 0;         /*  lower half of digits */
  register size_t count = 0;      /*  how many patterns */

  /*  odd number of digits cannot mirror */
  if ((dig10int(lower) & 1) || (dig10int(upper) & 1)) {
    return 0;
  }

  zeroes = (dig10int(lower)-1)/2;   /*  index of increments */
  magnitude = pow10int(zeroes+1);
  hi = lower / magnitude;
  lo = lower % magnitude;

  if (lo < hi) {
    lo = hi;
  }
  else if (lo == hi) {
    ;
  }
  else {
    hi++;
    lo = hi;
  }

  lower = (lo*magnitude) + lo;

  while (lower <= upper) {
    count += lower;
    lower += increments[zeroes];
  }

  return count;
}

static size_t
mirrored(const list_t *data)
{
  register size_t accumulator = 0;
  register const list_t *item = NULL;

  register size_t lo_digits = 0;
  register size_t hi_digits = 0;

  printf("\n");

  /*  restrict ranges to one magnitude each;
      85-108 becomes 85-99 and 100-108;
      42-69 remains intact
  */
  for (item = data; item; item = item->next) {
    lo_digits = dig10int(item->u.nn[0]);
    hi_digits = dig10int(item->u.nn[1]);

    if (lo_digits < hi_digits) {
      accumulator +=
        mirror(item->u.nn[0], pow10int(lo_digits)-1)  /*  85 - 99 */
        + mirror(pow10int(lo_digits), item->u.nn[1]); /*  100 - 108 */
    }
    else if (lo_digits == hi_digits) {
      accumulator += mirror(item->u.nn[0], item->u.nn[1]);
    }
    else {
      ;
    }
  }

  return accumulator;
}


static size_t
repeated(const list_t *data)
{
  return 0;
}

/*  extract each comma-separated range from one line of text
    and then each dash-separated range of two positives */
static list_t *
transform(list_t *data)
{
  register list_t *tail = NULL;

  register char *range = NULL;

  char *index = data->u.str.text;
  char *lower = NULL;
  char *upper = NULL;
  list_t tmp;

  tail = &tmp;

  /*  range points to the next (now) NULL-terminated "X-Y" form */
  while ((range = strsep(&index, ",")) != NULL) {

    /*  upper starts at the first but ends up at the second */
    upper = range;
    /*  lower receives the first */
    lower = strsep(&upper, "-");

    /*  store as numbers to the 'tmp' buffer space */
    tmp.u.nn[0] = strtoll(lower, NULL, 10);
    tmp.u.nn[1] = strtoll(upper, NULL, 10);

    /*  append the list with a copy of that scratch */
    tail->next = memdup((void *) &tmp, sizeof(list_t));
    tail = tail->next;

    /*  tail->next is now dirty, but we'll clobber it next time round */
  }

  /*  end the list here/now */
  tail->next = NULL;

  /*  dispose of the rest of the raw materials */
  free(data->u.str.text);
  free(data);

  /*  tmp.next (still) points to the first element */
  return tmp.next;
}


aoc_t *
gift_shop(list_t *data)
{
  aoc_t me = {
    .part1 = mirrored,
    .part2 = repeated,
    .data = transform(data),
  };

  return memdup((void*) &me, sizeof(me));
}

