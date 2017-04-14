
level:
	g++ level.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lpng -lz

level.o : level.o
	g++ -c level.h
	g++ -c level.cpp

all: $(OBJS) clean

clean : 
	-rm -f *.o $(EXENAME)
