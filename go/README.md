# Aoc2025 (Go (1.24.9)

Advent-of-Code 2025

Look at the `ginkgo` examples for each day's activities, they're named after the day that challenge came out.
The classes themselves are named otherwise more usefully.

The general approach is to transform the given sample and actual data into a list (of some sort) and then
perform transformations on that list. So you'll see all the class `initialize` methods have the same signature;
they take a list, a list of non-empty lines of text read from either sample or actual files, and do something
with it, leaving it in a frozen (read-only) state. Sometimes `initialize` performs the only needed transformation
right then and there, sometimes it leaves it open for other methods to molest^Wconsult.

The structure of the `ginkgo` tests is (so far) rather constant:

The first `context` block assigns the `subject` to a new instance of a particular class
initialized with the contents of a similarly-name sample data file that has been
transformed into list of non-`nil` line-termination-friendly elements.
The second `context` block does the same but for actual problem data.

Within each are `describe` blocks for both Part 1 and Part 2, the `Sample` context proving that the class
provides the correct answers as stated in the problem, and the `Actual` showing the answers to be submitted,
as well as proof that further tinkering hasn't broken anything (and a record of the answers themselves).

See `spec/aoc2025/template.rb` for each day's starting goodness.


##  Modules and Packages

In accordance with the [section on modules](https://go.dev/ref/mod#introduction),
it looks like my `aoc20205` _module_ shall be composed of the (collection of) source
files that satisfy the puzzles as one _package_ and the tests that prove them as a
second _package_. Now, how to separate the two, yet include them both in the module?

The _main module_ is still `dunsel.net/aoc2025` so I'm suspecting that I'll need
both a `dunsel.net/aoc20205/lib` and a `dunsel.net/aoc2025/spec` package.

That means that, for both package paths above, there are also `aoc2025` packages
thereunder, whhich may have files in them themselves.

Stuying `https://github.com/onsi/ginkgo/blob/master/types/types.go

```
% go install github.com/darthp8r/aoc-2025/go/lib

```


## Installation

Standard stuff:
Add this line to your application's Gemfile:

```go
import "aoc2025"
```

## Usage

You'll need `ginkgo` to get any action,

    $ ginkgo -v spec/ spec/aoc2025

`ginkgo` needs to know which folders to scan for a `_suite_test.go` file,
so give it all of them. Or, really, just give it `spec/aoc2025` because
reading in files to a list of strings is _done_.

To see the code, explore the `lib/aoc2025` folder.
To see how _to use_ the code, look through `spec/aoc2025` for each day's runs.
To see the answers, run the examples.

Examples are named after the day the puzzle came out, so that
1.  the classes themselves may preserve the puzzle _name_ as their own
1.  the most recent day's action appears last

Tell your computer `ginkgo spec --focus SecretEntrance` to run only those examples.


## Development

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake spec` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/[USERNAME]/aoc2025.
