package aoc2025

import (
	"strconv"
	"strings"
)

type rrange struct {
	Lo, Hi int
}

type GiftShop struct {
	Ranges []rrange
}



/*	Seems that idiomatic go is to have this New$(STRUCTNAME) constructor
	function that takes in the dependent data and creates the structure
	around whatever you do to said data, and returns a reference to same.
*/
func NewGiftShop(ranges []string) *GiftShop {
	me := &GiftShop {
		Ranges: make([]rrange, 0),
	}

	/*	This one's different, in that items are comma-separated vice line.
		Internally, express each range as a dash-separated natural numbers.
		Return a list of those pairs.
	*/

	for _, value := range strings.Split(ranges[0], ",") {
		//	is there a more idiomatic way?
		tmp := strings.Split(value, "-")
		lo, _ := strconv.Atoi(tmp[0])
		hi, _ := strconv.Atoi(tmp[1])

		item := rrange {
			Lo:	lo,
			Hi:	hi,
		}

		me.Ranges = append(me.Ranges, item)
	}

	return me
}


/*	Yes to dispatching the part1 or part2 algorithms against the same
	pre-processed list of ranges. Heh, my fifth language implementation,
	and I only now realize that the dispatch function logic could more
	easily handled by manipulating the input into the magnitude-bound
	ranges at initialization, and then apply the 'reduce()' to that list
	uninterrogated. :) I suppose I can claim total fidelity to the input,
	but there things that I know we can know we know going in. Shrug.
	Dispatch is kewl, tho
*/
func (me GiftShop) Mirrored() int {
	return me.dispatch(mirror)
}
//
func (me GiftShop) Repeated() int {
	return me.dispatch(repeat)
}


/*	Each range shall be restricted to the same power-of-ten; ranges
	that infringe into a higher power are split into two ranges and then
	summed. For example, the range 42-69 remains unchanged as one range,
	while the range 108-1066 gets split into 108-999 and 1000-1066 and
	then summed.
*/
func (me GiftShop) dispatch(f func(lower, upper int) int) int {
	accumulator := 0

	for _, item := range me.Ranges {
		lo_digits, hi_digits := Dig10(item.Lo), Dig10(item.Hi)

		/*	would love a ternary '<' (et al) operation */
		switch {

		/*	42-69 remain intact */
		case lo_digits == hi_digits:
			accumulator += f(item.Lo, item.Hi)

		/*	42-108 split into 42-99 and 100-108 */
		case lo_digits < hi_digits:
			crossover := Pow10(lo_digits)
			accumulator += f(item.Lo, crossover-1) + f(crossover, item.Hi)

		/*	I know, weird, but I wanted to have 'default' explicitly covered,
			*and* for 'switch' to return a value, i.e. accumulator += switch { }
		*/
		default:
			accumulator += 0
		}
	}

	return accumulator
}


/*	subsequent are no longer associated with the GiftShop type/struct(class);
	similar to (private) classmethods or namespaced (re-entrant!) functions
*/

func mirror(lower, upper int) int {
	/*	why I canna have const? */
	increments := []int {
		11,     	/*	11, 22, 33, 44 */
		101,    	/*	2323, 2424, 2525 */
		1001,   	/*	304304, 305305, 306306 */
		10001,  	/*	45064506, 45074507, 45084508 */
		100001, 	/*	5600756007, 5600856008, 5600956009 */ 
		1000001,	/*	670009670009, 670010670010, 670011670011 */
	}

	count := 0

	if (Dig10(lower) % 2) == 0 {
		zeroes := (Dig10(lower)-1) / 2
		magnitude := Pow10(1+zeroes)

		hi := lower / magnitude
		lo := lower % magnitude

		switch {
		case lo < hi:
			lo = hi
		case lo == hi:
		default:
			hi += 1
			lo = hi
		}

		/*	advance to the first possible match */
		lower = (lo*magnitude) + lo
		for ; lower <= upper; {
			count += lower
			lower += increments[zeroes]
		}
	}

	return count
}


func repeat(lower, upper int) int {
	count := 0
	magnitude := Dig10(lower)
	accumulator := make(map[int]int)

	if 0 < magnitude {
		halfitude := magnitude / 2
		for digits := 1; digits <= halfitude; digits++ {
			if (magnitude % digits) == 0 {
				copies := magnitude / digits
				sample := lower / Pow10(magnitude-digits)
				starter := 0
				increment := 0
				for shift := 0; shift < copies; shift++ {
					boost := Pow10(shift*digits)
					starter += sample * boost
					increment += boost
				}

				for partial := range repetition(starter, lower, upper, increment) {
					accumulator[partial] += 1
				}
			}
		}

		for partial := range accumulator {
			count += partial
		}
	}

	return count
}


func repetition(starter, lower, upper, increment int) map[int]int {
	for ; starter < lower; starter += increment {}

	acc := make(map[int]int)

	for ; starter <= upper; starter += increment {
		acc[starter] += 1
	}

	return acc
}


/*	integer 10^n */
func Pow10(n int) int {
	m := 1

	for exp := 0; exp < n; exp++ {
		m *= 10
	}

	return m
}

/*	integer number of base-10 digits */
func Dig10(n int) int {
	m := 10

	for digits := 1; digits < 12; digits++ {
		/*	style becomes syntax; 'else' must tightly cuddle */
		if n < m {
			return digits
		} else {
			m *= 10
		}
	}

	return 0
}

