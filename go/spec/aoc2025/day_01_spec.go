package aoc2025

import (
	"fmt"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"

	. "darthp8r.net/aoc2025/lib"
	. "darthp8r.net/aoc2025/support"
)

var _ = Describe("SecretEntrance", Label("SecretEntrance"), func() {
	Context("Sample", func() {
		subject := SecretEntrance { FileToList("aoc2025/day_01_sample.txt") }

		Describe("Part 1", Label("Zeroes"), func() {
			It("dunsels", func(ctx SpecContext) {
				subject.Zeroes()
			})

			It("sample data agrees", func(ctx SpecContext) {
				Expect(subject.Zeroes()).To(Equal(3))
			})
		})

		Describe("Part 2", Label("Clicks"), func() {
			It("sample data agrees", func(ctx SpecContext) {
				Expect(subject.Clicks()).To(Equal(6))
			})
		})
	})

	Context("Actual", func() {
		subject := SecretEntrance { FileToList("aoc2025/day_01_actual.txt") }

		Describe("Part 1", Label("Zeroes"), func() {
			It("actual answer above", func(ctx SpecContext) {
				fmt.Println(subject.Zeroes())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Zeroes()).To(Equal(1139))
			})
		})

		Describe("Part 2", Label("Clicks"), func() {
			It("actual answer above", func(ctx SpecContext) {
				fmt.Println(subject.Clicks())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Clicks()).To(Equal(6684))
			})
		})
	})

})

