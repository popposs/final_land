#include "level.h"


void system_events(){
    if(event.type == sf::Event::Closed){window.close();}
}

void init_map(){

}

void draw_map(){

}

void draw_all(){
	window.clear(sf::Color(0, 0, 0, 255));
	draw_map();
	window.display();
}

