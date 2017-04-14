#include "level.h"


void system_events(){
    if(event.type == sf::Event::Closed){window.close();}
}

void init_blocks(){
	rect.setSize(sf::Vector2f(50, 50));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(window_x / 2, 800 / 2);
}

void init_map(){
	
}

void draw_map(){

}

void draw_blocks(){
	sf::Vector2f pos = (sf::Vector2f) rect.getPosition();
	pos.x += rect_x_vel;
	pos.y += rect_y_vel;
	rect.setPosition(pos);
	window.draw(rect);
}

void draw_all(){
	window.clear(sf::Color(0, 0, 0, 255));
	draw_map();
	draw_blocks();
	window.display();
}

void key_pressed_events(){
    if(event.key.code == sf::Keyboard::Left)
		rect_x_vel += -1;
    if(event.key.code == sf::Keyboard::Right)
		rect_x_vel += 1;
    if (event.key.code == sf::Keyboard::Up)
		rect_y_vel += -1;
    if (event.key.code == sf::Keyboard::Down)
		rect_y_vel += 1;

}

void key_released_events(){
   if(event.key.code == sf::Keyboard::Left)
		rect_x_vel = 0;
   if(event.key.code == sf::Keyboard::Right)
		rect_x_vel = 0;
   if(event.key.code == sf::Keyboard::Up)
		rect_y_vel = 0;
   if(event.key.code == sf::Keyboard::Down)
		rect_y_vel = 0;
}


