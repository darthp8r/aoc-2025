#include <string.h>

#include <aoc2025.h>


/*  one plus 'n' zeroes */
/*  static */
size_t
pow10int(size_t n)
{
  register size_t m = 1;

  for (register size_t exp = 0; exp < n; exp++) {
    m *= 10;
  }

  return m;
}


/*  how many digits in this base-10 'n' */
/*  static */
size_t
dig10int(size_t n)
{
  register size_t m = 1;

  for (register size_t digits = 1; digits < 12; digits++) {
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
    than the upper bound
    */
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


/*  part two requires a rewrite of how the accumulator works;
    because part two requires the awareness of duplicate pattern
    discoveries, I believe I now need to make the accumulator into
    an ordered list, the penultimate action on which is to sum its
    natural number contents.
    */
static size_t
repetition(size_t lower, size_t upper, size_t magnitude, size_t digits)
{
  register size_t accumulator = 0;
  register size_t repetitive = 0;
  register size_t increment = 0;
  register size_t starter = 0;

  /*  which digit(s) shall repeat? */
  repetitive = lower / (pow10int(magnitude-digits));

  /*  repeat digit(s) at scale to get the increment (pattern) and the 
      first contestant */
  for (register size_t scale = 0; scale < magnitude; scale += digits) {
    increment += pow10int(scale);
    starter += repetitive * pow10int(scale);
  }

  /*  promote a premature starter value to the first one past the lower bound */
  while (starter < lower) {
    starter += increment;
  }

  /*  accumulate until out of range */
  while (starter <= upper) {
    accumulator += starter;
    starter += increment;
  }

  return accumulator;
}


/*  for each repetitive pattern for the magnitude of the lower bound,
    promote the lower bound to its first repetitive (if necessary),
    then add the appropriate increment until it's no longer less
    than the upper bound
    */
size_t
repeat(size_t lower, size_t upper)
{
  register size_t magnitude = dig10int(lower);
  register size_t accumulator = 0;
  register size_t pred = 0;
  register size_t next = 0;

  size_t cache[6] = { 0, 0, 0, 0, 0, 0, };

  /*  brute-force factoring, by modulus; whenever there's a remainder,
      there's only the one-digit pattern block size, otherwise that index
      is a factor to be used to generate a repetitive pattern
      */
  for (register size_t digits = 1; digits <= magnitude/2; digits++) {
    if (!(magnitude % digits)) {
      next = repetition(lower, upper, magnitude, digits);
      if (next != pred) {
        cache[digits] += next;
        accumulator += next;
        pred = next;
      }
    }
  }

  /*  remove all one-digit repetitives from each higher-power cache;
      for example, remove:
      2-2-2-2 from 22-22; 
      3-3-3-3-3-3 from 33-33-33 and 333-333;
      4-4-4-4-4-4-4-4 from 44-44-44-44 and 4444-4444;
      */
  for (register size_t digits = 2; digits <= magnitude/2; digits++) {
    if (cache[digits]) {
      accumulator -= cache[1];
    }
  }

  /*  remove all two-digit repetitives from a four-digit cache:
      44-44-44-44 from 4444-4444 (in addition to aboves)
      */
  if (cache[4]) {
    accumulator -= cache[2];
  }

  return accumulator;
}


/*  dispatch a function over the range for each data item, or
    sum dispatches for data that begin and end in different
    magnitudes. For example, dispatch() on the range 55-79
    calls the f() on that range, while dispatch() on the range
    308-4458 sums the call of f() on 308-999 and a call to f()
    on 1000-4458
    */
static size_t
dispatch(size_t (*f)(size_t, size_t), const list_t *data)
{
  register size_t accumulator = 0;
  register const list_t *item = NULL;

  register size_t lo_digits = 0;
  register size_t hi_digits = 0;

  /*  restrict ranges to one magnitude each;
      85-108 becomes 85-99 and 100-108;
      42-69 remains intact
  */
  for (item = data; item; item = item->next) {
    lo_digits = dig10int(item->u.nn[0]);
    hi_digits = dig10int(item->u.nn[1]);

    if (lo_digits < hi_digits) {
      accumulator +=
        f(item->u.nn[0], pow10int(lo_digits)-1)  /*  85 - 99 */
        + f(pow10int(lo_digits), item->u.nn[1]); /*  100 - 108 */
    }
    else if (lo_digits == hi_digits) {
      accumulator += f(item->u.nn[0], item->u.nn[1]);
    }
    else {
      ;
    }
  }

  return accumulator;
}


static size_t
mirrored(const list_t *data)
{
  return dispatch(mirror, data);
}


static size_t
repeated(const list_t *data)
{
  return dispatch(repeat, data);
}


/*  extract each comma-separated range from one line of text
    and then each dash-separated range of two positives
    */
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

