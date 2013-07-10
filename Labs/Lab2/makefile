all: build run

build: malltest.c
	gcc -g malltest.c -o l2
	gcc -g part5.c -o part5
run:
	valgrind ./l2
	./l2
	./part5
