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
  # Ruby's a little weird with its Proc indirection, but that's because
  # everything there has a value (gets evaluated), too. Although ...
  # ... a symbol would work there, too, come to think of it, but I wanna see
  # how I can do dispatch in go.
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
    magnitude = String.length(lo)

    # curious why I didn't need this test in other langauges
    # single-digit numbers cannot have repetitions
    #
    if magnitude == 1 do
      0

    else
       sum_map_set(
         Enum.reduce(1..div(magnitude, 2), MapSet.new, fn(digits, memo) ->
           if rem(magnitude, digits) == 0 do
             scale = div(magnitude, digits)
             starter = String.duplicate(String.slice(lo, 0..digits-1), scale)
             increment = String.duplicate(String.duplicate("0", digits-1) <> "1", scale)
             MapSet.union(
               memo,
               repetition(
                 String.to_integer(starter),
                 String.to_integer(lo), String.to_integer(hi),
                 String.to_integer(increment)))
           else
             memo
           end
         end)
       )
    end
  end

  defp repetition(starter, lower, upper, increment) do
    # promote starter past lower, if necessary
    if starter < lower do
      repetition(starter+increment, lower, upper, increment)

    # increment until out-of-bounds
    else
      Enum.reduce(starter..upper//increment, MapSet.new, fn(item, memo) ->
        MapSet.put(memo, item)
      end)
    end
  end

  defp sum_map_set(map_set) do
    Enum.reduce(MapSet.to_list(map_set), 0, fn(item, memo) ->
      memo + item
    end)
  end

# defp see_map_set(map_set, label) do
#   IO.puts "^ \"#{label}\""
#   Enum.map(MapSet.to_list(map_set), fn(me) ->
#     IO.puts "^ #{me}"
#   end)
#   nil
# end
end

