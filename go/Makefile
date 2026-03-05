# default task since it's first
.PHONY: all
all:  vet test

.PHONY: spec
spec: test

.PHONY: test
test:
	ginkgo -v spec/aoc2025
	#ginkgo -v spec/aoc2025 spec spec/support_spec

.PHONY: vet
vet:
	go vet ./...

#.PHONY: update-deps
#update-deps:
#	go get -u ./...
#	go mod tidy

.PHONY: setup
setup:
	go install github.com/onsi/ginkgo/v2/ginkgo
	$(info ! Add $${HOME}/go/bin to your $${PATH})
	go get github.com/onsi/gomega
	# go get -u ./...
	go mod tidy
	@echo go get darthp8r.net/aoc2025
	@echo go get darthp8r.net/aoc2025/spec

