all: server

server: server.c libfunc.a
	gcc -lm -o server server.c -L. -lfunc


func.o: func.c func.h
	gcc -O -c func.c

libfunc.a: func.o 
	ar rcs libfunc.a func.o
	
libs: libfunc.a

clean:
	rm -f server *.o *.a *.gch
