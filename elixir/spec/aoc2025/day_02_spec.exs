require Aoc2025.GiftShop

defmodule Aoc2025Spec.Day02 do
  use ESpec

  context "Sample" do
    subject(Aoc2025.GiftShop.gift_shop(
      Aoc2025Spec.Support.file_to_list String.replace(__ENV__.file, "_spec.exs", "_sample.txt")))

    describe "Part 1" do
      it "sample data agrees" do
        subject = Aoc2025Spec.Day02.subject
        expect(Aoc2025.GiftShop.mirrored(subject)) |> to(eq 1227775554)
      end
    end

    describe "Part 2" do
      it "sample data agrees" do
        subject = Aoc2025Spec.Day02.subject
        expect(Aoc2025.GiftShop.repeated(subject)) |> to(eq 4174379265)
      end
    end
  end

  context "Actual" do
    subject(Aoc2025.GiftShop.gift_shop(
      Aoc2025Spec.Support.file_to_list String.replace(__ENV__.file, "_spec.exs", "_actual.txt")))

    describe "Part 1" do
      it "actual answer above" do
        subject = Aoc2025Spec.Day02.subject
        IO.puts Aoc2025.GiftShop.mirrored(subject)
      end

      it "results survive" do
        subject = Aoc2025Spec.Day02.subject
        expect(Aoc2025.GiftShop.mirrored(subject)) |> to(eq 38158151648)
      end
    end

    describe "Part 2" do
      it "actual answer above" do
        subject = Aoc2025Spec.Day02.subject
        IO.puts Aoc2025.GiftShop.repeated(subject)
      end

      it "results survive" do
        subject = Aoc2025Spec.Day02.subject
        expect(Aoc2025.GiftShop.repeated(subject)) |> to(eq 45283684555)
      end
    end
  end

end
