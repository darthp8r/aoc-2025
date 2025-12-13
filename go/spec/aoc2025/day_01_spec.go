package aoc2025

import (
	"fmt"

	. "github.com/onsi/ginkgo/v2"
//	. "github.com/onsi/gomega"

	. "darthp8r.net/aoc2025/lib"
	. "darthp8r.net/aoc2025/support"
)

var _ = Describe("SecretEntrance", Label("secret_entrance"), func() {
	Context("Sample", func() {
		subject := SecretEntrance(FileToList("aoc2025/day_01_sample.txt"))

		It("dunsels", func(ctx SpecContext) {
			fmt.Printf("Sample Size of %v\n", subject)
		})
	})

	Context("Actual", func() {
		subject := SecretEntrance(FileToList("aoc2025/day_01_actual.txt"))

		It("dunsels", func(ctx SpecContext) {
			fmt.Printf("Sample Size of %v\n", subject)
		})
	})

})

