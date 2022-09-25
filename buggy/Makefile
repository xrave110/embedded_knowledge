buggy:
	clang buggy.c -g -o buggy.o

buggycc: # target name
	gcc buggy.c -o buggy.o

clean:  # target name
	rm -rf buggy.o

run:
	./buggy.o

debug:
	gdb ./buggy.o