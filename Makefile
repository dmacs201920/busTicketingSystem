PRO:	functions.o	main.o
	gcc -g -o $@ $^
functions.o:	functions.c	header.h
	gcc -g -c $<
main.o:	main.c	header.h
	gcc -g -c $<
clean:
	rm functions.o main.o
