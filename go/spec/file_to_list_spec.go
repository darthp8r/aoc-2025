package aoc2025

import (
	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"

	. "darthp8r.net/aoc2025/support"
)

var _ = Describe("Transpose a data file into a list of strings", Label("file_to_list"), func() {
	var subject []string

	subject = FileToList("/tmp/file_to_list.txt")

	It("three lines", func(ctx SpecContext) {
		//	expect length to be three
		Expect(len(subject)).To(Equal(3))
	})

	It("separates lines", func(ctx SpecContext) {
		//	expect contents to be ["payter", "is a", "hosehead"]
		Expect(subject[0]).To(Equal("payter"))
		Expect(subject[1]).To(Equal("is a"))
		Expect(subject[2]).To(Equal("hosehead"))
	})
})

