package aoc2025

import (
	"fmt"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"

	. "darthp8r.net/aoc2025/lib/aoc2025"
	. "darthp8r.net/aoc2025/spec/support"
)

var _ = Describe("GiftShop", func() {
	Context("Sample", func() {
		subject := NewGiftShop(FileToList("day_01_sample.txt"))

		Describe("Part 1", Label("Mirrored"), func() {
			It("sample data agrees", func(ctx SpecContext) {
				Expect(subject.Mirrored()).To(Equal(1227775554))
			})
		})

		Describe("Part 2", Label("Repeated"), func() {
			It("sample data agrees", func(ctx SpecContext) {
				Expect(subject.Repeated()).To(Equal(4174379265))
			})
		})
	})

	Context("Actual", func() {
		subject := NewGiftShop(FileToList("day_01_actual.txt"))

		Describe("Part 1", Label("Mirrored"), func() {
			It("actual answer below", func(ctx SpecContext) {
				fmt.Println(subject.Mirrored())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Mirrored()).To(Equal(38158151648))
			})
		})

		Describe("Part 2", Label("Repeated"), func() {
			It("actual answer below", func(ctx SpecContext) {
				fmt.Println(subject.Repeated())
			})

			It("results survive", func(ctx SpecContext) {
				Expect(subject.Repeated()).To(Equal(45283684555))
			})
		})
	})

})

