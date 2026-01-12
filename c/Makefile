#!/usr/bin/env gmake
#
# gonna try to re-create the magic from inside spookville
#
NAME := aoc2025
ROOT := $(realpath .)

#	where to find the deployables
#
#DEPLOY := $(addprefix export/,lib tests)
#
#$(DEPLOY):
#	@mkdir -p $@


include version.mk

include lib/makeinc.mk
include spec/support/makeinc.mk
include spec/makeinc.mk


.PHONY: default
default:	all

.PHONY: dunsel
dunsel: #| $(DEPLOY)
	$(info LIBRARY  $(LIBRARY))
	$(info OBJECTS  $(OBJECTS))
	$(info SUPPORT  $(SUPPORT))
	$(info EXAMPLES $(EXAMPLES))

.PHONY: all
all: $(LIBRARY) #| $(DEPLOY)


.PHONY: test
test:	spec

.PHONY: spec
spec: $(LIBRARY) $(SUPPORT) $(EXAMPLES)
	@for spec in \
		spec/support_spec/file_to_list_spec \
		spec/aoc2025_spec \
		$(shell find spec/aoc2025 -type f -name \*_spec); do $${spec}; done


.PHONY: clean
clean:
#	@rm -fr $(DEPLOY)
	@find lib spec -type f \( -name \*.a -or -name \*.o -or -name \*_spec \) | xargs rm -f

.PHONY: over
over:	clean all

###	EOF
