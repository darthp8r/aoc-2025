
#
PYTHON ?= python3.11
VIRTUALDIR ?= virtual
PIPSNEEDED ?= 

define virtually
	@. $(VIRTUALDIR)/bin/activate; $1 $2 $3 $4 $5 $6 $7
endef

.PHONY: all
all: setup
	$(call virtually, PYTHONPATH=. mamba spec)

.PHONY: spec
spec: | $(VIRTUALDIR)
	$(call virtually, PYTHONPATH=. mamba spec)

.PHONY: setup
setup: $(VIRTUALDIR)

$(VIRTUALDIR):
	$(info creating the virtual environment ...)
	$(PYTHON) -m venv $(VIRTUALDIR)
	$(call virtually, pip install --upgrade pip)
	$(call virtually, pip install -e .)

