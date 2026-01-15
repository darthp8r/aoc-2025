#   Advent of Code 2025, Polyglot Edition

_Implementations in ruby, python, go, elixir, c, but probably not cobol_

Ruby because I love it.
Python and Go because they're popular.
Elixir because cool.
C because kids.
COBOL (maybe) because it keeps surfacing in my news feeds or other interest vehicles.

This year it's [FreeBSD](https://www.freebsd.org) 14.3-RELEASE for my development environment.

| language  | version   | pkg install   | testing       | notes |
| --------- | --------- | ------------- | ------------- | ------------- |
|   ruby    |   3.4.7   |   ruby-3      |   rspec       |   3.3.9 system, 3.4.7 virtualized in rvm  |
|   python  |   3.11.13 |   python311   |   mamba       |   |
|   go      |   1.24-13 |   go          |   ginkgo      |   |
|   elixir  |   1.17    |   elixir      |   espec       |   erlang 26.2.5.15,4  |
|   c       |   19.1.7  |   (n/a)       |   bdd-for-c   |   |
|   cobol   |   3.2-3   |   gnucobol    |   UNK         |   |

Support structures

|   support     |   version     |   role    |
|   ----------- |   ----------- |   --- |
|   lynx        |   2.8.9.1-3.1 |   text/console web browser    |
|   markdown    |   1.0.1-2     |   convert markdown to html    |
|   pandoc      |   3.8.1-1     |   hs-pandoc convert markdown to html    |
|   rtd_theme   |   1.0.0-1     |   sphinx documentation generator theme    |


##  Write All About It

Each `README.md` file talks about each language's peculiarities individually:
the `docs` folder talks about them comparitively. Built using `sphinx` and its
`read-the-docs` theme.

```
sphinx-quickstart
    --sep
    -p "Advent of Code 2025, Polyglot Edition"
    -a DarthP8r
    -v 2025
    -r 2025
    -l en
    --ext-todo
    --ext-viewcode
    --ext-githubpages
    --makefile
    sphinx
```


##  General Approach

Tests not only prove correctness, but instruct on proper (and improper!) usage.
That's probably why they're called _examples_ in TDD/BDD culture.

Therefore, each challenge shall be met with an associated example on the code built
for that challenge.

Code files (and container names) for the challenge are named after the challenge title.
For example, the class/module/namespace for the first day's challenge will be called
`Aoc2025.SecretEntrance` (properly cased and punctuated).
Filenames follow convention: `lib/aoc2025/secret_entrance.XYZ`

Examples and data files are named after the n^th^ day, and reference the appropriate class/module/namespace;
the first day's examples live in `spec/aoc2025/day_01_spec.XYZ` and work with either
`spec/aoc2025/day_01_sample.txt` (copied from the challenge description)
or
`spec/aoc2025/day_01_actual.txt` (downloaded).

Data sets are stored in a top-level `data` folder,
alongside each of the `elixir`, `go`, `python`, and `ruby` folders,
and then copied into each language's local space (see the [`Makefile`] up top).

>   Note:
>   Copying (once) seemed easier than having each example go up the three or so folders for that day's data


##  Data Contract

Each day's challenge arrives in two parts, each using the same _sample_ and _actual_ data sets.
The _sample_ data sets are easily copied from the challenge page,
and the downloaded _actual_ data set will be assumed to be just as clean as the sample set.

Meaning we can eschew some defensive programming by assuming that the data files exist
(because I put them there)
and that they're both internally intact
(there are no errors in the data, aside from problem design).

Therefore, the first task for each language is to implement a `file_to_list` behavior, stored
alongside the test structures
(transforming a file into a list is a support role, but only for testing),
that reads each line from a data file into each language's idiomatic (linked-)list of strings.

Code honors the list-of-strings convention throughout.
Objects (or equivalents) are initialized with and only with one such trusted list.
Makes things easy.


##  Modular

The module name in each language shall be `Aoc2025` (properly cased).
Code for that module, be it a gem, wheel, package, or mixture,
is rooted at the `lib` or `src` folder, whichever is custom.
Examples for that module are rooted in the `spec` folder parallel
to the module's code.

> `go` conventionally (as far as I can tell) keeps tests in the same folder as the code.
> I like that and I don't, so I'll revert to stubbornness by keeping faithful with the `spec`
> folder for examples.


##  Testing

I'm maniacal about ruby's `rspec`. Maniacal.
Greatest thing since Woodbury Kitchen's _Hot Buttered Rum_
but with none of the caloric commitment.
You'll see the test structure repeated for each language.

The module names for examples will differ for each language;
see respective `README` for details for whatever works.

Overall, for each example file, there are two top-level `Context` blocks,
one for the _Sample_ data set and one for the _Actual_ challenge data.

Within each of these contexts are two `Description` blocks, one for _Part 1_ and one for _Part 2_.

### Sample

For the sample data sets, we're given the answer, so the method under test, for both Parts,
only need to agree with the challenge text.

> sometimes I'll have a no-op `dunsels` example to show that the method doesn't panic;
> if you see these then that's sloppiness on my part

### Actual

For the actual data sets, there are two examples for each Part,
one to print out the result for that run,
and one to assert that value, once discovered.
The value assertion doubles as a guard against regressions.


##  Epilogue

Sneak-preview README markdown in a browser.
It's not totally faithful, because text, but it's nice to see how what I've written may express.

```
pandoc -r markdown -w html README.md | lynx -stdin
```

