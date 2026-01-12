#include <aoc2025.h>

#include "file_to_list.h"

#include "bdd-for-c.h"

spec("Gift Shop") {
  static aoc_t *subject = NULL;

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
      it("sample data agrees") {
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
      it("actual answer ==>") {
        printf("%lu ", subject->part2(subject->data));
      }

      xit("results survive") {
        check(subject->part2(subject->data) == 6684);
      }
    }
  }
}

