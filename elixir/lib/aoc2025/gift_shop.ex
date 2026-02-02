require Integer

defmodule Aoc2025.GiftShop do
  def gift_shop data do
    List.first(
      Enum.map(data, fn(lyne) ->
        Enum.map(String.split(lyne, ","), fn(range) ->
          String.split(range, "-")
        end)
      end)
    )
  end

  def mirrored ranges do
    dispatch(:mirror, ranges)
  end

  def repeated ranges do
    dispatch(:repeat, ranges)
  end

  # Yeah, thanks, C, for imposing an environment where a function dispatch
  # is the grokkest choice for manipulating the incoming data in the same
  # way needed by both/all transformers. Should've used in python, too.
  # Ruby's a little weird with its Proc indirection, but that' because
  # everything there has a value, too. A symbol would work there, too, come
  # to think of it, but I'm now looking forward to how I can do this in go.
  #
  defp dispatch(f, ranges) do
    Enum.reduce(ranges, 0, fn(item, memo) ->
      [lo, hi] = item
      lo_digits = String.length(lo)
      hi_digits = String.length(hi)
      memo +
        cond do   # a spaceship <=> operator could turn this into a 'case'
          lo_digits == hi_digits ->
            apply(Aoc2025.GiftShop, f, [lo, hi])

          # returning apply(one) + apply(two) seems to drop one of the resultants;
          # only did splitting them out and assigning them explicitly honored both
          lo_digits < hi_digits ->
            lesser = apply(Aoc2025.GiftShop, f, [lo, String.duplicate("9", lo_digits)])
            greater = apply(Aoc2025.GiftShop, f, ["1" <> String.duplicate("0", lo_digits), hi])
            lesser + greater

          true ->
            0
        end
    end)
  end

  def mirror(lo, hi) do
    if Integer.is_odd(String.length(lo)) do
      0

    else
      magnitude = Integer.pow(10, div(String.length(lo), 2))
      lo = String.to_integer(lo)
      hi = String.to_integer(hi)

      lo_upper = div(lo, magnitude)
      lo_lower = rem(lo, magnitude)
    # hi_upper = div(hi, magnitude)
    # hi_lower = rem(hi, magnitude)
    # funny, it was all about the 'lo' value the whole time :)

      [lo_upper, lo_lower] =
        cond do
          lo_lower < lo_upper -> [lo_upper, lo_upper]
          lo_lower == lo_upper -> [lo_upper, lo_lower]
          true -> [lo_upper + 1, lo_upper + 1]
        end

      lo = (lo_upper * magnitude) + lo_lower
    # hi = (hi_upper * magnitude) + hi_lower
      if lo <= hi do
        Enum.reduce(lo..hi//(1+magnitude), 0, fn(item, memo) ->
          memo + item
        end)
      else
        0
      end

    end
  end

  def repeat(lo, hi) do
    IO.puts "REPEATED #{lo} #{hi}"
    #lo * hi
    88
  end
end

