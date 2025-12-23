//	*must* have `_test` as the suffix; won't recognize `aoc2025_spec`
package aoc2025_test

import (
	"testing"

	. "github.com/onsi/ginkgo/v2"
	. "github.com/onsi/gomega"
)

/*	Seems pretty boilerplate, as in it doesn't allow to separate or segregate
**	which files comprise the suite to run. Also doesn't seem to care about
**	naming collisions, as long as there's an `_suite_test.go` file in a folder,
**	the examples in that folder will run.
*/
func TestAoc2025(t *testing.T) {
	RegisterFailHandler(Fail)
	RunSpecs(t, "Aoc2025 Spec Support")
}

