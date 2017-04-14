#ifndef LEVEL_MAIN_H
#define LEVEL_MAIN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
using namespace std;

int window_x = 1280;		
int window_y = 800;

sf::Event event;
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Level");

sf::RectangleShape rect;
int rect_x_vel, rect_y_vel;

void system_events();
void init_blocks();
void init_map();
void draw_all();

void key_pressed_events();
void key_released_events();

int main(){
	srand(time(NULL));
	init_map();	
	init_blocks();

	while(window.isOpen()){
		event = sf::Event();

		while(window.pollEvent(event)){
			system_events();

			if(event.type == sf::Event::KeyPressed)
				key_pressed_events();
			if(event.type == sf::Event::KeyReleased)
				key_released_events();
		}
		draw_all();
	}
	return EXIT_SUCCESS;
};

#endif
