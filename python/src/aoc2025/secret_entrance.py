#!/usr/bin/env python3
#

class SecretEntrance:

  def __init__(self, turns=list()):
    self.turns = [[turn[0], int(turn[1:].strip())] for turn in turns]
    pass

  def zeroes(self):
    combo = 0
    position = 50

    for (direction, amount) in self.turns:
      if direction == 'L':
        position -= amount
      elif direction == 'R':
        position += amount

      position %= 100
      if not position:
        combo += 1

    return(combo)

  def clicks(self):
    combo = 0
    position = 50

    for (direction, amount) in self.turns:

      # every 100 def clicks
      combo += int(amount / 100)
      amount %= 100

      if direction == 'L':
        if (100 if position == 0 else position) <= amount:
          combo += 1
        position -= amount

      elif direction == 'R':
        if 100 <= (position + amount):
          combo += 1
        position += amount

      position %= 100

    return(combo)

