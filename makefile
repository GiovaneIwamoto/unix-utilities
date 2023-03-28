CC=gcc
CFLAGS=-Wall -Werror

all: wcat wgrep wzip wunzip

wcat: wcat.c
	$(CC) -o wcat wcat.c $(CFLAGS)

wgrep: wgrep.c
	$(CC) -o wgrep wgrep.c $(CFLAGS)

wzip: wzip.c
	$(CC) -o wzip wzip.c $(CFLAGS)

wunzip: wunzip.c
	$(CC) -o wunzip wunzip.c $(CFLAGS)

clean:
	rm -f wcat wgrep wzip wunzip