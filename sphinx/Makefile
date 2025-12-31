# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
SOURCEDIR     = source
BUILDDIR      = build
#
VIRTUALDIR    = virtual
PIPSNEEDED    = sphinx sphinx-readable-theme
#
define virtually
	@. $(VIRTUALDIR)/bin/activate; $1 $2 $3 $4 $5 $6 $7
endef


# Put it first so that "make" without argument is like "make help".
help: | $(VIRTUALDIR)
	@$(call virtually,$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O))

.PHONY: help Makefile

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile | $(VIRTUALDIR)
	@$(call virtually,$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O))


$(VIRTUALDIR):
	$(info creating the virtual environment ...)
	@python -m venv $(VIRTUALDIR)
	$(call virtually, pip install --upgrade pip)
	$(call virtually, pip install $(PIPSNEEDED))

