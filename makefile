all: prog
prog: myBank.c main.c
	gcc -Wall myBank.c main.c -o prog

.PHONY: clean all

clean:
	rm -f prog

