package aoc2025_test

import (
	"testing"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"
)

/*	seems pretty boilerplate, as in it doesn't allow to separate or segregate
**	which files comprise the suite to run
*/
func TestAoc2025(t *testing.T) {
	RegisterFailHandler(Fail)
	RunSpecs(t, "Aoc2025 Suite")
}
