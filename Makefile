CC=gcc
CFLAGS=-Wall -Wextra -Iheaders
CFILES=$(wildcard src/*.c)
HFILES=$(wildcard headers/*.h)

run:
	$(CC) $(CFLAGS) -o run $(CFILES) $(HFILES)
test:
	python ./tests/generate_file.py
debug:
	$(CC) $(CFLAGS) -g -o run $(CFILES) $(HFILES)

clean: run
	rm run