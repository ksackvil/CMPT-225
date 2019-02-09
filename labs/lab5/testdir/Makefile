
x:	main.o Stack.o
	g++ -o x Stack.o main.o

main.o:	main.cpp Stack.h
	g++ -c main.cpp

Stack.o:	Stack.cpp Stack.h
	g++ -c Stack.cpp

clean:	
	rm -f *.o x *.out
