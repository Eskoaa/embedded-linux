CC = arm-linux-gnueabihf-gcc
src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lwiringPi -lpthread -lcrypt -ltr -lm

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) 

.PHONY: clean
clean:
	rm -f $(obj) myprog
