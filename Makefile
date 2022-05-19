CC=gcc
CFLAGS=-Iheaders
CFILES=$(wildcard src/*.c)
HFILES=$(wildcard headers/*.h)

run:
	$(CC) $(CFLAGS) -o run $(CFILES) $(HFILES)

clean: run
	rm run