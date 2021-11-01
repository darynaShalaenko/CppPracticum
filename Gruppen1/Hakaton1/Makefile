all: clean SetTest
	

SetTest: SetFile.o PolyFile.o main.o
	gcc -o SetTest SetFile.o PolyFile.o main.o

SetFile.o:
	gcc SetFile.c Predicat.c -c 

PolyFile.o:
	gcc PolyFile.c Predicat.c -c

main.o:
	gcc main.c -c  

clean:
	rm -f *.o SetTest 




