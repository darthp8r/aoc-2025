
$(EXAMPLES): %_spec: %_spec.c $(SUPPORT) $(LIBRARY)
	$(CC) -Iinclude -Ispec/support -Ibdd-for-c -o $@ $< -Llib -Lspec/support -l$(NAME) -l$(NAME)spec

