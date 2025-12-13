package aoc2025

import (
	"fmt"
)

func SecretEntrance(turns []string) int {
	//	repeat the list, again, to show I'm here
	for i, turn := range turns {
		fmt.Printf("(%02v) %c%s%c\n", i, '"', turn, '"')
	}

	return len(turns)
}
