
SUB = g++ -pedantic-errors

game.o : game.cpp game.h
	$(SUB) -c game.cpp
main.o : main.cpp main.h
	$(SUB) -c main.cpp
util.o : util.cpp util.h
	$(SUB) -c util.cpp
game : game.o main.o util.o
	$(SUB) game.o main.o util.o -o game
clean :
	rm -f *.o game
.PHONY : clean
