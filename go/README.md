# Aoc2025 (Go 1.24.9)

Advent-of-Code 2025

>   Note: lots of copy-pasta from the ruby README


##  Installation

Standard stuff:
Add this line to your application's _require_ clause in `go.mod`

```
github.com/darthp8r/aoc2025 v2.2025.0
```


##  Usage

```go
require github.com/darthp8r/aoc2025
```


### Testing

_`ginkgo` is RSpec for go_

>   Need to finalize, hopefully move `support` to under `spec`

    $ ginkgo -v spec/ spec/aoc2025
    $ ginkgo -v spec/ spec/support_spec spec/aoc2025 (?)
    $ ginkgo -v spec/aoc2025 --focus SecretEntrance`


##  Development

`ginkgo` needs to know which folders to scan for a `_suite_test.go` file,
so give it all of them. Or, really, just give it `spec/aoc2025` because
reading in files to a list of strings is _done_.

Tell your computer `ginkgo spec/aoc2025 --focus SecretEntrance` to run only those examples.

In accordance with the [section on modules](https://go.dev/ref/mod#introduction),
it looks like my `aoc20205` _module_ shall be composed of the (collection of) source
files that satisfy the puzzles as one _package_ and the tests that prove them as a
second _package_. Now, how to separate the two, yet include them both in the module?

That means that, for both package paths above, there are also `aoc2025` packages
thereunder, whhich may have files in them themselves.

Studying `https://github.com/onsi/ginkgo/blob/master/types/types.go

    $ go install github.com/darthp8r/aoc-2025/go/lib

