src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lz -lm

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) 
