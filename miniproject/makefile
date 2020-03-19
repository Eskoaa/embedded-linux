src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lwiringPi -lwiringPiDev -lz -lm

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog
