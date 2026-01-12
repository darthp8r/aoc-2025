#	Prep the development environment for each language:
#	1.	copies all the sample and actual data files
#	1.	generates the version number from the number of test files
#
#	$1 language
#	$2 test folder
#	$3 test suffix
#
define hoser
	@mkdir -p $(1)/$(2)/aoc2025
	@echo 2025.$(words $(wildcard $(1)/$(2)/aoc2025/day_*$(3))) > $(1)/VERSION
	@ln -f data/day_??_*.txt $(1)/$(2)/aoc2025
endef

.PHONY: default
default: all


.PHONY: ruby
ruby:
	$(call hoser,ruby,spec,_spec.rb)

.PHONY: python
python:
	$(call hoser,python,spec,_spec.py)

.PHONY: go
go:
	$(call hoser,go,spec,_spec.go)

.PHONY: elixir
elixir:
	$(call hoser,elixir,spec,_spec.elx)

.PHONY: c
c:
	$(call hoser,c,spec,_spec.c)


.PHONY: sphinx
sphinx:
	@cd sphinx; $(MAKE) html


.PHONY: all
all:	ruby python go elixir sphinx c

