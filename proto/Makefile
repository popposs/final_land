stage_main.o :
	g++ -c level.h
	g++ -c level.cpp
	g++ -c stage.cpp
	g++ -c tile.cpp
	g++ -c keyboard.cpp
	g++ -c utils.cpp
	g++ -c slime.cpp
	g++ -c dark_adept.cpp
	g++ level_main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lpng -lz

all: $(OBJS) clean

clean : 
	-rm -f *.o $(EXENAME)
