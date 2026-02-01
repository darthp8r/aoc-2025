module Aoc2025
  RSpec.describe GiftShop do
    context "Sample" do
      before(:all) do
        @subject = GiftShop.new Support.file_to_list __FILE__.gsub('spec.rb', 'sample.txt')
      end
      subject { @subject }

      describe "Part 1" do
        it "sample data agrees" do
          expect(subject.mirrored).to eq 1227775554
        end
      end

      describe "Part 2" do
        it "sample data agrees" do
          expect(subject.repeated).to eq 4174379265
        end
      end
    end

    context "Actual" do
      before(:all) do
        @subject = GiftShop.new Support.file_to_list __FILE__.gsub('spec.rb', 'actual.txt')
      end
      subject { @subject }

      describe "Part 1" do
        it "actual answer above" do
          pp subject.mirrored
        end

        it "results survive" do
          expect(subject.mirrored).to eq 38158151648
        end
      end

      describe "Part 2" ,:skip do
        it "actual answer above" do
          pp subject.repeated
        end

        it "results survive" do
          expect(subject.repeated).to eq 45283684555
        end
      end
    end
  end
end

