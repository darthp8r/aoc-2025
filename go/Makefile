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

