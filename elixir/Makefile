# default task since it's first
.PHONY: all
all:  test

.PHONY: spec
spec: test

.PHONY: test
test:
	MIX_ENV=test mix espec --trace

.PHONY: update-deps
update-deps:
	@echo

.PHONY: setup
setup:
	MIX_ENV=test mix espec.init

