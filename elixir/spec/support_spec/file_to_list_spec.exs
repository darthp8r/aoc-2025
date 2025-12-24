require Aoc2025Spec.Support

defmodule Aoc2025Spec.SupportSpec do
  use ESpec

  subject(Aoc2025Spec.Support.file_to_list String.replace(__ENV__.file, "_spec.exs", ".txt"))

  describe "Aoc2025Spec.Support.file_to_list" do

    it "three lines" do
      expect(length(Aoc2025Spec.SupportSpec.subject)) |> to(eq 3)
    end

    it "separates lines" do
      expect(Aoc2025Spec.SupportSpec.subject) |> to(eq ["payter", "is a", "hosehead"])
    end

  end

end
