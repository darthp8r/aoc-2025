#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <aoc2025.h>

int
shine(const char *text)
{
  if (text) {
    /*
      30  black
      31  red
      32  green
      33  yellow (brown)
      34  blue
      35  magenta
      36  cyan
      37  grey
      38  white
    */
    return printf("\e[7:38m%s\e[m", text);
    /*
      0   normal
      1   bright
      2   dim
      3   a little less dim
      4   underscore
      5   blinkenlights
      6   just like 3 ?
      7   inverse
    */
  }
  else {
    return 0;
  }
}


void *
memdup(const void *source, size_t length)
{
  register void *target = (void *) malloc(length);

  if (target) {
    memcpy(target, source, length);
  }

  return target;
}

