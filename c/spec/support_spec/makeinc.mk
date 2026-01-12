$(info spec/support-spec builds file_to_list_spec)

spec/support_spec/file_to_list_spec: spec.support_spec/file_to_list_spec.c $(SUPPORT)
	$(CC) -Iinclude -Ispec/support -Ibdd-for-c -o $@ $<

