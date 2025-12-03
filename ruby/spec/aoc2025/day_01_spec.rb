module Aoc2025
  RSpec.describe SecretEntrance do
    context "Sample" do
      before(:all) do
        @subject = SecretEntrance.new Support.file_to_list __FILE__.gsub('spec.rb', 'sample.txt')
      end
      subject { @subject }

      describe "Part 1" do
        it "dunsels" do
          subject.zeroes
        end

        it "sample data agrees" do
          expect(subject.zeroes).to eq 3
        end
      end

      describe "Part 2" do
        it "sample data agrees" do
          expect(subject.clicks).to eq 6
        end
      end
    end

    context "Actual" do
      before(:all) do
        @subject = SecretEntrance.new Support.file_to_list __FILE__.gsub('spec.rb', 'actual.txt')
      end
      subject { @subject }

      describe "Part 1" do
        it "actual answer above" do
          pp subject.zeroes
        end

        it "results survive" do
          expect(subject.zeroes).to eq 1139
        end
      end

      describe "Part 2" do
        it "actual answer above" do
          pp subject.clicks
        end

        it "results survive" do
          expect(subject.clicks).to eq 6684
        end
      end
    end
  end
end

