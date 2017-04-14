level.o :
	g++ -c level.cpp
	g++ level.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lpng -lz

all: $(OBJS) clean

clean : 
	-rm -f *.o $(EXENAME)
