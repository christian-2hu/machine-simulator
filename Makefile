output: main.o
	gcc bin/main.o -o bin/main

main.o:
	gcc -c src/main.c -o bin/main.o

clean:
	rm bin/*.o bin/main