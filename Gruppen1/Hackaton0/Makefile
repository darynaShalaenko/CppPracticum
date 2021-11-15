all: clean testChemp


SetTest: match.o team.o analyze.o tests.o
	gcc -o testChemp match.o team.o analyze.o

SetFile.o:
	gcc team.c -c 

PolyFile.o: 
	gcc match.c -c

analyze.o:
	gcc analyze.c -c  

tests.o:
	gcc tests.c -c 

clean:
	rm -f *.o testChemp 


