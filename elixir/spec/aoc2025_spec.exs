require Aoc2025

defmodule Aoc2025Spec do
  use ESpec

  describe "Aoc2025 Shared Methods" do
    it "shine is shiny" do
      text = "c73945c8-e049-11f0-a9ed-34159e1b1f98"

    # IO.puts Aoc2025.shine text
      expect(String.length(Aoc2025.shine(text)))
      |>  to(eq 10+String.length(text))
    end
  end

end

