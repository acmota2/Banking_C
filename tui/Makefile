CC=gcc
VG=valgrind
VFLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

run: run.c
	$(CC) -o run -g run.c funcs.c funcs.h op1.c op1.h op2.c op2.h op3.c op3.h op4.c op4.h op5.c op5.h utils_tui.c utils_tui.h

runV: run 
	$(VG) $(VFLAGS) --log-file=vout.txt ./run

cleanV: vout.txt
	rm vout.txt

clean: run
	rm run