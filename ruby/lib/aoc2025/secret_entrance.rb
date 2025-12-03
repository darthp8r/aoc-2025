module Aoc2025
  class SecretEntrance
    attr_reader :turns

    def initialize turns=[]
      @turns = turns.inject([]) do |memo, item|
        memo.append [item[0], item[1..].to_i]
        memo
      end
    end

    def zeroes
      combo = 0

      @turns.inject(50) do |position, vector|
        direction, amount = vector
        if direction == 'L'
          position -= amount
        elsif direction == 'R'
          position += amount
        end

        position %= 100
        combo += 1 if position.zero?
        position
      end

      combo
    end

    def clicks
      combo = 0

      @turns.inject(50) do |position, vector|
        direction, amount = vector

        # every 100 def clicks
        combo += amount / 100
        amount %= 100

        # click if we scoot past or land on zero
        if direction == 'L'
          # amounts larger than the position click (use 100 for zero)
          combo += 1 if (position.zero? ? 100 : position) <= amount
          position -= amount
        elsif direction == 'R'
          # amounts that move the position past 100 click
          combo += 1 if 100 <= position + amount
          position += amount
        end

        position % 100
      end

      combo
    end

  end
end
