PRO:	functions.o	main.o
	gcc -o $@ $^
functions.o:	functions.c	header.h
	gcc -c $<
main.o:	main.c	header.h
	gcc -c $<
clean:
	rm functions.o main.o
