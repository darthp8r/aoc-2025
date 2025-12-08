package aoc2025_support

import (
	"bufio"
	"os"
	"strings"
)

func FileToList(filename string) []string {
	lyst := make([]string, 0)

	file, oops := os.Open(filename)
	if (oops == nil) {
		defer file.Close()

		scanner := bufio.NewScanner(file)
		for scanner.Scan() {
			text := strings.TrimSpace(scanner.Text())
			if len(text) > 0 {
				lyst = append(lyst, text)
			}
		}
	}

	return lyst
}

