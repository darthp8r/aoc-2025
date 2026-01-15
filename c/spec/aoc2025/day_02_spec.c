#include <aoc2025.h>

#include "file_to_list.h"

#include "bdd-for-c.h"

spec("Gift Shop") {
  static aoc_t *subject = NULL;

  context("Support Structures") {
    describe("pow10int: ten to the power 'n'") {
      extern size_t pow10int(size_t);

      it("pow10int(0) is one") {
         check(pow10int(0) == 1);
      }

      it("pow10int(2) is a hundred") {
         check(pow10int(2) == 100);
      }

      it("pow10int(9) is a trillion") {
         check(pow10int(9) == 1000000000);
      }
    }

    describe("dig10int: number of digits, base ten") {
      extern size_t dig10int(size_t);

      it("dig10int(1) is one") {
        check(dig10int(1) == 1);
      }

      it("dig10int(7) is one") {
        check(dig10int(7) == 1);
      }

      it("dig10int(99) is two") {
        check(dig10int(99) == 2);
      }

      it("dig10int(100) is three") {
        check(dig10int(100) == 3);
      }

      it("dig10int(123456) is six") {
        check(dig10int(123456) == 6);
      }
    }
  }

  context("Sample") {
    before() {
      subject = gift_shop(file_to_list("spec/aoc2025/day_02_sample.txt"));
    }

    describe("Part 1") {
      it("sample data agrees") {
        check(subject->part1(subject->data) == 1227775554);
      }
    }

    describe("Part 2") {
      xit("sample data agrees") {
        check(subject->part2(subject->data) == 4174379265);
      }
    }
  }

  context("Actual") {
    before() {
      subject = gift_shop(file_to_list("spec/aoc2025/day_02_actual.txt"));
    }

    describe("Part 1") {
      it("actual answer ==>") {
        printf("%lu ", subject->part1(subject->data));
      }

      it("results survive") {
        check(subject->part1(subject->data) == 38158151648);
      }
    }

    describe("Part 2") {
      xit("actual answer ==>") {
        printf("%lu ", subject->part2(subject->data));
      }

      xit("results survive") {
        check(subject->part2(subject->data) == 6684);
      }
    }
  }
}

