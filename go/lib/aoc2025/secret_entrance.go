package aoc2025

import (
	"strconv"
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

	//	encode left turns as negative
	for _, turn := range turns {
		amount, _ := strconv.Atoi(turn[1:])
		switch turn[0] {
		case 'L':
			me.Turns = append(me.Turns, amount * -1)
		case 'R':
			me.Turns = append(me.Turns, amount)
		default:
			//
		}
	}

	return me
}


func (me SecretEntrance) Zeroes() int {
	combination := 0
	position := 50

	for _, turn := range me.Turns {
		position += turn
		position %= 100
		if position == 0 {
			combination++
		}
	}

	return combination
}


func (me SecretEntrance) Clicks() int {
	combination := 0
	position := 50
	landing := 0

	for _, turn := range me.Turns {
		if turn < 0 {
			combination -= turn / 100
		} else {
			combination += turn / 100
		}
		landing = position + (turn % 100)

		switch {
		case landing < 0:
			if position != 0 {
				combination++
			}
			position = landing + 100
		case landing == 0:
			combination++
			position = landing
		case landing < 100:
			position = landing
		default:
			combination++
			position = landing - 100
		}
	}

	return combination
}

