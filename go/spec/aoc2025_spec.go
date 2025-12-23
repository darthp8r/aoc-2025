package aoc2025_test

import (
//	"fmt"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"

	. "darthp8r.net/aoc2025/lib"
)

var _ = Describe("Aoc2025", Label("Aoc2025"), func() {
	Context("Generic", func() {
		It("shines", func(ctx SpecContext) {
			Expect(Shine("shiney")).To(Equal(1+2+3))
		})
	})

})

