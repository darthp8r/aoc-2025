defmodule Aoc2025 do
  def shine(text) do
    # 30  black
    # 31  red
    # 32  green
    # 33  yellow (brown)
    # 34  blue
    # 35  magenta
    # 36  cyan
    # 37  grey
    # 38  white
    "\e[7;38m" <> "#{text}" <> "\e[m"
    # 0   normal
    # 1   bright
    # 2   dim
    # 3   a little less dim
    # 4   underscore
    # 5   blinkenlights
    # 6   just like 3 ?
    # 7   inverse
  end
end

