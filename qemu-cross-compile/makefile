CC = /home/adminub/newhd/cross-pi-gcc-9.2.0-0/bin/arm-linux-gnueabihf-gcc-9.2.0
src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lpthread -lcrypt 

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) 

.PHONY: clean
clean:
	rm -f $(obj) myprog
