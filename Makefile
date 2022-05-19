CC=gcc
CFLAGS=-Iheaders
CFILES=$(wildcard src/*.c)
HFILES=$(wildcard headers/*.h)

run:
	$(CC) $(CFLAGS) -g -o run $(CFILES) $(HFILES)

clean: run
	rm run