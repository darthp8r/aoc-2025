package aoc2025

/*
import (
	"strconv"
)
*/

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

	return me
}


func (me GiftShop) Mirrored() int {
	return 0
}


func (me GiftShop) Repeated() int {
	return 0
}

