CC=gcc
CFLAGS=-Wall -MMD -D__UNITTEST__

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)

all: unittest

unittest: $(OBJS)
	$(CC)  $(CFLAGS) -o $@ $^ -ltalloc

clean:
	rm -rf $(OBJS) $(DEPS)

-include $(DEPS)
