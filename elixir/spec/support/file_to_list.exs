defmodule Aoc2025.Support do

  # return a list of non-empty lines
  #
  def file_to_list filename do
    File.stream!(filename)
    |>  Stream.map(&String.trim/1)
    |>  Enum.reject(fn line -> String.length(line) == 0 end)
  end

  # temporary; will go away once file_to_list/1 is correct
  #
  def main do
    lyst = file_to_list "/tmp/file_to_list.txt"

  # IO.puts("lyst=<#{lyst}>") # again, victim of the print statement

    Enum.each(lyst, fn item -> IO.puts("<#{item}>") end)
  end
end

# elixir spec/support/file_to_list.exs
#
Aoc2025.Support.main()

