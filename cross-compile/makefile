CC = arm-linux-gnueabihf-gcc
src = $(wildcard *.c)
obj = $(src:.c=.o)
LIB := lib
LDFLAGS = -lwiringPi -lm -lpthread -lrt -lcrypt

myprog: $(src)
	$(CC) -o $@ -L$(LIB) $^ $(LDFLAGS)  

.PHONY: clean
clean:
	rm -f $(obj) myprog
