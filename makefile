all: sl.c ml.c t.c
	gcc sl.c ml.c t.c
run: all
	./a.out
clean:
	rm a.out