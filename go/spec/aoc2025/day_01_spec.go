package aoc2025

import (
	"fmt"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"

	. "darthp8r.net/aoc2025/lib/aoc2025"
	. "darthp8r.net/aoc2025/spec/support"
)

var _ = Describe("SecretEntrance", Serial, func() {
	Context("Sample", func() {
		subject := NewSecretEntrance(FileToList("day_01_sample.txt"))

		Describe("Part 1", Label("Zeroes"), func() {
			It("dunsels", func(ctx SpecContext) {
				subject.Zeroes()
			})

			//	ruby and python evaluate (-1244 % 100) to 56; just saying
			//	those codes didn't represent left turns as negative, though
			It("modulus (%) preserves sign", func(ctx SpecContext) {
				Expect(-1244 % 100).To(Equal(-44))
			})

			//	ruby evaluates (-1244 / 100) to -13
			//	python evaluates int(-1244 / 100) to -12
			//	go agrees with python
			It("whole division (/) preserves sign", func(ctx SpecContext) {
				Expect(-1244 / 100).To(Equal(-12))
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
		subject := NewSecretEntrance(FileToList("day_01_actual.txt"))

		Describe("Part 1", Label("Zeroes"), func() {
			It("actual answer below", func(ctx SpecContext) {
				fmt.Println(subject.Zeroes())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Zeroes()).To(Equal(1139))
			})
		})

		Describe("Part 2", Label("Clicks"), func() {
			It("actual answer below", func(ctx SpecContext) {
				fmt.Println(subject.Clicks())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Clicks()).To(Equal(6684))
			})
		})
	})

})

