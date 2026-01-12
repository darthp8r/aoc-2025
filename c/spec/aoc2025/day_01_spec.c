#include <aoc2025.h>

#include "file_to_list.h"

#include "bdd-for-c.h"

spec("Secret Entrance") {
  static aoc_t *subject = NULL;

  context("Sample") {
    before() {
      subject = secret_entrance(file_to_list("spec/aoc2025/day_01_sample.txt"));
    }

    describe("Part 1") {
      it("sample data agrees") {
        check(subject->part1(subject->data) == 3);
      }
    }

    describe("Part 2") {
      it("sample data agrees") {
        check(subject->part2(subject->data) == 6);
      }
    }
  }

  context("Actual") {
    before() {
      subject = secret_entrance(file_to_list("spec/aoc2025/day_01_actual.txt"));
    }

    describe("Part 1") {
      it("actual answer ==>") {
        printf("%lu ", subject->part1(subject->data));
      }

      it("results survive") {
        check(subject->part1(subject->data) == 1139);
      }
    }

    describe("Part 2") {
      it("actual answer ==>") {
        printf("%lu ", subject->part2(subject->data));
      }

      it("results survive") {
        check(subject->part2(subject->data) == 6684);
      }
    }
  }
}

