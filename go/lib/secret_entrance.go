package aoc2025

import (
	"strconv"
	"fmt"
)

type SecretEntrance struct {
	Turns []int
}


/*	Seems that idiomatic go is to have this New$(STRUCTNAME) constructor
	function that takes in the dependent data and creates the structure
	around whatever you do to said data, and returns a reference to same.
*/
func NewSecretEntrance(turns []string) *SecretEntrance {
	me := &SecretEntrance {
		Turns: make([]int, 0),
	}

	for _, turn := range turns {
		amount, _ := strconv.Atoi(turn[1:])
		switch turn[0] {
		case 'L':
			me.Turns = append(me.Turns, amount * -1)
		case 'R':
			me.Turns = append(me.Turns, amount)
		default:
			me.Turns = append(me.Turns, 0)
		}
	}

	return me
}


func (me SecretEntrance) Dunsel() int {
	fmt.Println(me.Turns)

	return len(me.Turns)
}

func (me SecretEntrance) Zeroes() int {
	return len(me.Turns)
}

func (me SecretEntrance) Clicks() int {
	return len(me.Turns)
}

