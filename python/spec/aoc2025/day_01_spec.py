#!/usr/bin/env python3
#
from mamba import description, context, it
from expects import expect, equal

import spec.support
from aoc2025 import SecretEntrance

with description('SecretEntrance'):
  with context('Sample'):
    with before.all:
      self.subject = SecretEntrance(
          spec.support.file_to_list(__file__.replace('spec.py', 'sample.txt')))

    with description('Part 1'):

      with it('sample data agrees'):
        expect(self.subject.zeroes()).to(equal(3))

    with description('Part 2'):

      with it('sample data agrees'):
        expect(self.subject.clicks()).to(equal(6))


  with context('Actual'):
    with before.all:
      self.subject = SecretEntrance(
          spec.support.file_to_list(__file__.replace('spec.py', 'actual.txt')))

    with description('Part 1'):

      with it('actual answer above'):
        print(self.subject.zeroes())

      with it('results survive'):
        expect(self.subject.zeroes()).to(equal(1139))

    with description('Part 2'):

      with it('actual answer above'):
        print(self.subject.clicks())

      with it('results survive'):
        expect(self.subject.clicks()).to(equal(6684))

