EXAMPLES := $(patsubst %_spec.c,%_spec,$(shell find spec -type f -name \*_spec.c))
#
$(EXAMPLES): %_spec: %_spec.c $(SUPPORT)
	$(CC) -Iinclude -Ispec/support -Ibdd-for-c -o $@ $< -Llib -Lspec/support -l$(NAME) -l$(NAME)spec

