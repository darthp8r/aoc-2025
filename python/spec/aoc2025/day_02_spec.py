#!/usr/bin/env python3
#
from mamba import description, context, it
from expects import expect, equal

import spec.support
from aoc2025 import GiftShop

with description('GiftShop'):
  with context('Sample'):
    with before.all:
      self.subject = GiftShop(
          spec.support.file_to_list(__file__.replace('spec.py', 'sample.txt')))

    with description('Part 1'):

      with it('sample data agrees'):
        expect(self.subject.mirrored()).to(equal(1227775554))

    with _description('Part 2'):

      with it('sample data agrees'):
        expect(self.subject.repeated()).to(equal(4174379265))


  with context('Actual'):
    with before.all:
      self.subject = GiftShop(
          spec.support.file_to_list(__file__.replace('spec.py', 'actual.txt')))

    with description('Part 1'):

      with it('actual answer above'):
        print(self.subject.mirrored())

      with it('results survive'):
        expect(self.subject.mirrored()).to(equal(38158151648))

    with _description('Part 2'):

      with it('actual answer above'):
        print(self.subject.repeated())

      with it('results survive'):
        expect(self.subject.repeated()).to(equal(45283684555))

