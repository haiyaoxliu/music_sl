
all: list.o music_lib.o test.o
	gcc -o mlib list.o music_lib.o test.o

list.o: list.c list.h
	gcc -c list.c

music_lib.o: music_lib.c music_lib.h list.c list.h
	gcc -c music_lib.c

test.o: test.c list.h music_lib.h
	gcc -c test.c

run: all
	./mlib

clean:
	rm mlib
	rm *.o
	rm *~