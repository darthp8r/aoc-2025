#   Advent of Code 2025, Polyglot Edition

_Implementations in ruby, python, go, maybe elixir, and maybe-maybe cobol_

Ruby because I love it. Python and Go because they're popular. Elixir because new. COBOL because old.

I'll commit to ruby, python, and go,
try to get me some elixir exposure,
and probably not get very far at all with COBOL.

This year it's [FreeBSD](https://www.freebsd.org) 14.3-RELEASE for my development environment.

| language  | version   | pkg install   | testing   | notes |
| --------- | --------- | ------------- | --------- |   ---------   |
|   ruby    |   3.4.7   |   ruby-3      |   rspec   |   3.3.9 system, 3.4.7 virtualized in rvm  |
|   python  |   3.11.13 |   python311   |   mamba   |   |
|   go      |   1.24-13 |   go          |   ginkgo  |   |
|   elixir  |   1.17    |   elixir      |   UNK     |   erlang 26.2.5.15,4  |
|   cobol   |   3.2-3   |   gnucobol    |   UNK     |   |

Support structures

|   support     |   version     |   role    |
|   ----------- |   ----------- |   --- |
|   lynx        |   2.8.9.1-3.1 |   text/console web browser    |
|   markdown    |   1.0.1-2     |   convert markdown to html    |
|   pandoc      |   3.8.1-1     |   hs-pandoc convert markdown to html    |

##  Because

Because the data is the same, keep them all in the `data` folder at the project root.
This may not be a very clean premise, as for each language's packing processes require
access to those data files.

In the past for ruby, I've included a `cp` command in the `Rakefile` that brings data
from a nearby/shared folder locally so that the gem would have its own copy. Not a fan.
