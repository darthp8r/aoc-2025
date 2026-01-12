OBJECTS := lib/$(NAME).o $(patsubst %.c,%.o,$(wildcard lib/$(NAME)/*.c))
#
$(OBJECTS): %.o: %.c
	$(CC) -Iinclude -o $@ -c $<

LIBRARY := lib/lib$(NAME).a
#
$(LIBRARY): $(OBJECTS) #| $(DEPLOY)
	ar -rc $@ $(OBJECTS)

