package main

import (
	"fmt"

	.	"darthp8r.net/aoc2025/support"
)

func main() {
	for i, item := range FileToList("/tmp/file_to_list.txt") {
		fmt.Printf("%02v\t%c%s%c\n", i, '"', item, '"')
	}
}

