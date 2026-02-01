module Aoc2025
  class GiftShop
    attr_reader :ranges

    # this time we're told there is only one line of text
    #
    def initialize ranges=[]
      @ranges = ranges[0].split(',').inject([]) do |memo, item|
        memo.append item.split '-'
        memo
      end
    end

    def mirrored
      @ranges.inject(0) do |memo, (lo, hi)|
        memo +
          if lo.length == hi.length
            mirror(lo, hi)
          elsif lo.length < hi.length
            mirror(lo, "9" * lo.length) + mirror("1" + "0" * lo.length, hi)
          else
            0
          end
      end
    end

    private def mirror(lo, hi)
      return 0 if lo.length.odd? or hi.length.odd?

      magnitude = 10 ** (lo.length / 2)
      lo = lo.to_i
      hi = hi.to_i

      lo_upper, lo_lower = (lo / magnitude), (lo % magnitude)
      hi_upper, hi_lower = (hi / magnitude), (hi % magnitude)

      # determine where to start incrementing
      if lo_lower < lo_upper          # 84 promotes to 88
        lo_lower = lo_upper
      elsif lo_lower == lo_upper      # 66 remains
        nil
      else                            # 48 promotes to 55
        lo_upper += 1
        lo_lower = lo_upper
      end

      lo = (lo_upper * magnitude) + lo_lower
      hi = (hi_upper * magnitude) + hi_lower
      return 0 unless lo <= hi   # promoted the lower bound out of bounds

      (lo..hi).step(1+magnitude).inject(0) do |memo, item|
        memo + item
      end
    end

    def repeated
      @ranges.inject(0) do |memo, (lo, hi)|
        memo +
          if lo.length == hi.length
            repeats(lo, hi)
          elsif lo.length < hi.length
            repeats(lo, "9" * lo.length) + repeats("1" + "0" * lo.length, hi)
          else
            0
          end
      end
    end

    # lo and hi are still strings
    private def repeats(lo, hi)
      magnitude = lo.length

      (1..magnitude/2).inject(Set.new) do |memo, digits|
        if (magnitude % digits).zero?
          scale = magnitude / digits
          starter = lo[0...digits] * (scale)
          increment = ("0"*(digits-1) + "1") * (scale)
          memo += repetition(starter.to_i, lo.to_i, hi.to_i, increment.to_i)
        end
        memo
      end.inject(0) do |memo, item|
        memo + item
      end
    end

    # all arguments are not integers
    private def repetition(starter, lower, upper, increment)

      # promote the starting value to the first above the lower bound
      while starter < lower
        starter += increment
      end

      # keep incrementing valid matches
      (starter..upper).step(increment).inject(Set.new) do |memo, item|
        memo.add item
      end
    end

  end
end
