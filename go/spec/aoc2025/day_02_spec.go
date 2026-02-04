package aoc2025

import (
	"fmt"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"

	. "darthp8r.net/aoc2025/lib/aoc2025"
	. "darthp8r.net/aoc2025/spec/support"
)

var _ = Describe("GiftShop", func() {
	Context("Supports", Pending, func() {
		Describe("Pow10", func() {
			It("10^0 is 1", func(ctx SpecContext) {
				Expect(Pow10(0)).To(Equal(1))
			})

			It("10^1 is 10", func(ctx SpecContext) {
				Expect(Pow10(1)).To(Equal(10))
			})

			It("10^5 is 100000", func(ctx SpecContext) {
				Expect(Pow10(5)).To(Equal(100000))
			})
		})

		Describe("Dig10", func() {
			It("6 has ONE digit", func(ctx SpecContext) {
				Expect(Dig10(6)).To(Equal(1))
			})

			It("42 has TWO digits", func(ctx SpecContext) {
				Expect(Dig10(42)).To(Equal(2))
			})

			It("100 has THREE digits", func(ctx SpecContext) {
				Expect(Dig10(100)).To(Equal(3))
			})

			It("10000 has FIVE digits", func(ctx SpecContext) {
				Expect(Dig10(10000)).To(Equal(5))
			})

			It("32768 has FIVE digits", func(ctx SpecContext) {
				Expect(Dig10(32768)).To(Equal(5))
			})
		})
	})

	Context("Sample", func() {
		subject := NewGiftShop(FileToList("day_02_sample.txt"))

		Describe("Part 1", func() {
			It("sample data agrees", func(ctx SpecContext) {
				Expect(subject.Mirrored()).To(Equal(1227775554))
			})
		})

		Describe("Part 2", func() {
			It("sample data agrees", func(ctx SpecContext) {
				Expect(subject.Repeated()).To(Equal(4174379265))
			})
		})
	})

	Context("Actual", func() {
		subject := NewGiftShop(FileToList("day_02_actual.txt"))

		Describe("Part 1", func() {
			It("actual answer below", func(ctx SpecContext) {
				fmt.Println(subject.Mirrored())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Mirrored()).To(Equal(38158151648))
			})
		})

		Describe("Part 2", func() {
			It("actual answer below", func(ctx SpecContext) {
				fmt.Println(subject.Repeated())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Repeated()).To(Equal(45283684555))
			})
		})
	})

})

