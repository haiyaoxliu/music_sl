all: list.c
	gcc list.c
run: all
	./a.out
clean:
	rm a.out