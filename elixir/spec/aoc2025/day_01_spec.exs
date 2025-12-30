require Aoc2025.SecretEntrance

defmodule Aoc2025Spec.Day01 do
  use ESpec

  describe "Modulus and Division" do
    it "positive div" do
      expect(div(1230, 100)) |> to(eq 12)
    end

    it "positive rem" do
      expect(rem(1230, 100)) |> to(eq 30)
    end

    it "negative div" do
      expect(div(-1230, 100)) |> to(eq -12)
    end

    it "negative rem" do
      expect(rem(-1230, 100)) |> to(eq -30)
    end
  end

  context "Sample" do
    subject(Aoc2025.SecretEntrance.secret_entrance(
      Aoc2025Spec.Support.file_to_list String.replace(__ENV__.file, "_spec.exs", "_sample.txt")))

    describe "Part 1" do
      it "sample data agrees" do
        subject = Aoc2025Spec.Day01.subject
        expect(Aoc2025.SecretEntrance.zeroes(subject)) |> to(eq 3)
      end
    end

    describe "Part 2" do
      it "sample data agrees" do
        subject = Aoc2025Spec.Day01.subject
        expect(Aoc2025.SecretEntrance.clicks(subject)) |> to(eq 6)
      end
    end
  end

  context "Actual" do
    subject(Aoc2025.SecretEntrance.secret_entrance(
      Aoc2025Spec.Support.file_to_list String.replace(__ENV__.file, "_spec.exs", "_actual.txt")))

    describe "Part 1" do
      it "actual answer above" do
        subject = Aoc2025Spec.Day01.subject
        IO.puts Aoc2025.SecretEntrance.zeroes(subject)
      end

      it "results survive" do
        subject = Aoc2025Spec.Day01.subject
        expect(Aoc2025.SecretEntrance.zeroes(subject)) |> to(eq 1139)
      end
    end

    describe "Part 2" do
      it "actual answer above" do
        subject = Aoc2025Spec.Day01.subject
        IO.puts Aoc2025.SecretEntrance.clicks(subject)
      end

      it "results survive" do
        subject = Aoc2025Spec.Day01.subject
        expect(Aoc2025.SecretEntrance.clicks(subject)) |> to(eq 6684)
      end
    end
  end

end
