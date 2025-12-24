defmodule Aoc2025Spec.Support do

  # return a list of non-empty lines
  #
  def file_to_list filename do
    File.stream!(filename)
    |>  Stream.map(&String.trim/1)
    |>  Enum.reject(fn line -> String.length(line) == 0 end)
  end

end

