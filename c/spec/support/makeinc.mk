#	file_to_list is only used by the spec/examples apps
#
spec/support/file_to_list.o: spec/support/file_to_list.c
	$(CC) -Iinclude -Ispec/support -o $@ -c $<

$(SUPPORT): spec/support/file_to_list.o
	$(AR) -rc $@ $<

