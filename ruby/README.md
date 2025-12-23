#   Aoc2025 (Ruby 3.4.7)

Advent-of-Code 2025

>   Note OG


##  Installation

Standard stuff:
Add this line to your application's Gemfile:

```ruby
gem 'aoc2025'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install aoc2025


##  Usage

```ruby
require 'aoc2025'
```


##  Testing

You'll need `rspec` to get any action, so do the same installation steps with `rspec` vice `aoc2025`

    $ rspec spec

To see the code, explore the `lib/aoc2025` folder.
To see how _to use_ the code, look through `spec/aoc2025` for each day's runs.
To see the answers, run the examples.

Examples are named after the day the puzzle came out, so that
1.  the classes themselves may preserve the puzzle _name_ as their own
1.  the most recent day's action appears last

Tell your computer `rspec spec -e TreacheryOfWhales` to run only those examples,
or, if you know the day, say `rspec spec/aoc2025/day_07_spec.rb` instead.


##  Development

`rvm` places you in a virtual environment.

After checking out the repo, run `bin/setup` to install dependencies. Then, run `rake spec` to run the tests. You can also run `bin/console` for an interactive prompt that will allow you to experiment.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

