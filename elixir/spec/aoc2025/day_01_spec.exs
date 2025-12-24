defmodule Aoc2025Spec.Day01 do
  use ESpec

  context "Sample" do
    subject(Aoc2025Spec.Support.file_to_list String.replace(__ENV__.file, "_spec.exs", "_sample.txt"))

    describe "Part 1" do
      it "dunsels" do
        IO.puts length(Aoc2025Spec.Day01.subject)
      end

      it "sample data agrees" do
      end
    end

    describe "Part 2" do
      it "sample data agrees" do
      end
    end

  end

  context "Actual" do
    subject(Aoc2025Spec.Support.file_to_list String.replace(__ENV__.file, "_spec.exs", "_actual.txt"))

    describe "Part 1" do
      it "actual answer above" do
      end

      it "results survive" do
      end
    end

    describe "Part 2" do
      it "actual answer above" do
      end

      it "results survive" do
      end
    end
  end

end
