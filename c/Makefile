#
# gonna try to re-create the magic from inside spookville
#
NAME := aoc2025
ROOT := $(realpath .)

include version.mk

#	where to find the deployables
#
#DEPLOY := $(addprefix export/,lib tests)
#
#$(DEPLOY):
#	@mkdir -p $@


# it seems that targets expressed as variables need to be defined here
# why? before other targets? for the PHONY target to notice
#
LIBRARY := lib/lib$(NAME).a
SUPPORT := spec/support/lib$(NAME)spec.a
EXAMPLES := $(patsubst %_spec.c,%_spec,$(shell find spec -type f -name \*_spec.c))


.PHONY: default
default:	all

.PHONY: all
all: $(LIBRARY)

.PHONY: support
support: $(SUPPORT)

.PHONY: test
test:	spec

.PHONY: spec
spec: $(LIBRARY) $(SUPPORT) $(EXAMPLES)

.PHONY: runner
runner: spec
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

.PHONY: dunsel
dunsel: #| $(DEPLOY)
	$(info LIBRARY  $(LIBRARY))
	$(info OBJECTS  $(OBJECTS))
	$(info SUPPORT  $(SUPPORT))
	$(info EXAMPLES $(EXAMPLES))


#	now that all the targets are named and accounted for,
#	cook them according to each's recipes
#
include lib/makeinc.mk
include spec/support/makeinc.mk
include spec/makeinc.mk

###	EOF
