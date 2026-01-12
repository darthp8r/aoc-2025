#   Aoc2025 (c clang 19.7.1)

Yup, `rspec` testing to prove challenge apps, again.

```
git submodule add https://github.com/grassator/bdd-for-c
```

The main game here is the `bdd-for-c.h` file, included in and only in
the example apps under the `spec` folder.

Also under the `spec` folder is the `support/file_to_list.c` utility that
reads from (sample and actual) data files and builds a linked-list of
non-empty lines.

Of course that utility has its own test!
See `spec/support_spec/file_to_list_spec.c`


##  Daily Challenges

Each daily challenge works on a list of non-empty character strings,
where that list can come from anywhere. For day-to-day simplicity,
that list arrives from (and only from) the test/example apps.

It's a re-re-reincarnation of any `blob_t` type we've all written
ten thousand times over.

```c
typedef struct list_s {
    char *text;
    size_t strlen;
    struct list_s *next;
} list_t;
```

In keeping with the luxury that we can trust the fidelity of each day's
challenge text (error free outside the business logic aspect), challenge
codes will assume that the incoming linked-list is intact.

That brings me to the infamous _naming_ conundrum. Other (higher-level)
languages covered this year do all the list management and namespacing
as first-class properties, whether object-oriented by module and class
or more functional by module and structured data.

For `C`, each challenge's `contructor` accepts the aforementioned linked-list
as raw material, optionally transforming it, and then returning a structure
of that possibly-modified linked-list and two function pointers, named
`part1` and `part2` respectively, not out of a paucity of creativity,
but more out of a recognition that new days' codes and tests are more easily
added to the total package.

>   Note:
>   Maybe I should adopt that convention for the other languages.
>   I do enjoy learning new optimizations and organizational lessons
>   with each new language. :)

```c
typedef struct aoc_s {
    const list_t *data;
    size_t (*part1)(const list_t *data);
    size_t (*part2)(const list_t *data);
} aoc_t;
```

>   Note:
>   I'm assuming that each challenge returns an unsigned integral value.
>   If I learn otherwise, then I'll get to address that "breaking change"
>   for each day's work.

Usage:

```c
aoc_t *subject = challenge_title(file_to_list("/path/to/datafile"));

subject->part2(subject->data);
```


##  Testing

Testing not only shows resiliency towards certain bugs,
but also how _to use_ what it is you're testing.
Ideally, there'd be no molesting the code, and `bdd-for-c`
does just that:

Usage:

```c
#include "bdd-for-c.h"

#include <aoc2025.h>

spec("test this") {
  ...
}

```

In reality, given the `part1` an `part2` contract taken above, each test
templates down to this:

```c
#include <aoc2025.h>

#include "file_to_list.h"

#include "bdd-for-c.h"

spec("Challenge Title") {
  static aoc_t *subject = NULL;

  context("Sample") {
    before() {
      subject = challenge_title(file_to_list("spec/aoc2025/day_XY_sample.txt"));
    }

    describe("Part 1") {
      it("sample data agrees") {
        check(subject->part1(subject->data) == PART1_SAMPLE_ANSWER);
      }
    }

    describe("Part 2") {
      it("sample data agrees") {
        check(subject->part2(subject->data) == PART2_SAMPLE_ANSWER);
      }
    }
  }

  context("Actual") {
    before() {
      subject = challenge_title(file_to_list("spec/aoc2025/day_XY_actual.txt"));
    }

    describe("Part 1") {
      it("actual answer ==>") {
        printf("%lu\n", subject->part1(subject->data));
      }

      it("results survive") {
        check(subject->part1(subject->data) == PART1_ACTUAL_ANSWER);
      }
    }

    describe("Part 2") {
      it("actual answer ==>") {
        printf("%lu\n", subject->part2(subject->data));
      }

      it("results survive") {
        check(subject->part2(subject->data) == PART2_ACTUAL_ANSWER);
      }
    }
  }
}

```

All that really changes is the argument to the `file_to_list` reader.


##  So Sue Me

You'll notice I don't bother with calling `free(1)` anywhere except in the
file-reading support function. I'm intentionally letting it all leak out
on `exit(1)` because that nitty-gritty isn't (as) germane to solving each
challenge, at least not nearly as much as allocting memory is necessary.

##  Semicolophon

I know, I know, I know, `register` doesn't add anything, and may even end
up putting the variable on the stack after all. Yeah? So what.

Even though that argument may _technically_ be true (for gcc 4 and earlier,
certain processors, blah blah blah), I use `register` not for the "efficiency"
claims from the 1980's, but to indicate to you, dear reader, that that
variable will be modified _only with its defined scope_ and nowhere else.
Because a `register` variable cannot have its address evaluated, it will
never be modified by reference somewhere else.

Using it is informative, not to the compiler (any more), but to future-me
or present-you or future-y'all. It's almost like `static` in its file-scope
usage: it doesn't change the _behavior_ of the code because how that function
gets called doesn't change (although that function is now visible outside
of that file, and assembly `jump` instructiond may get reworked, the
no-behavioral-change argument holds, even if weaker than `register` use.

So, yeah. `register`

