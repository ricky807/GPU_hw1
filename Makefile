
output:main.o linkedList.o
	gcc main.o linkedList.o -o main
	./main testfile2
mainBonus.o:main.c linkedList.h
	gcc -c main.c
LinkedListString_testBonus.o:linkedList.c linkedList.h
	gcc -c linkedList.c
clean:
	rm *.o main

