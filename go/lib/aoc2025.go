package aoc2025

import "fmt"

//	TODO	change to variadic when you're ready
func Shine(text string) int {

  //  30  black
  //  31  red
  //  32  green
  //  33  yellow (brown)
  //  34  blue
  //  35  magenta
  //  36  cyan
  //  37  grey
  //  38  white -----\
  fmt.Printf("\x1b[7;38m%s\x1b[m", text)
  //  0   normal --/
  //  1   bright
  //  2   dim
  //  3   a little less dim
  //  4   underscore
  //  5   blinkenlights
  //  6   just like 3 ?
  //  7   inverse

  return len(text)
}

