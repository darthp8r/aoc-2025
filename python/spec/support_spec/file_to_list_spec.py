#!/usr/bin/env python3
#
from mamba import description, context, it
from expects import expect, equal

import spec.support

with description('file_to_list') as self:
  with before.all:
    self.subject = spec.support.file_to_list(__file__.replace('_spec.py', '.txt'))

  with it("three lines"):
    expect(len(self.subject)).to(equal(3))

  with it("separates lines"):
    expect(self.subject).to(equal(["payter", "is a", "hosehead"]))

