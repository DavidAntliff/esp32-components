CC=gcc
CFLAGS=-ggdb

all: classical three_step

.PSEUDO: clean
clean:
	rm -f classical three_step

