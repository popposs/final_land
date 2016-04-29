#include <SFML/Graphics.hpp>
#include <iostream>


void move_sprite(sf::Sprite & sprite, int & x_vel, int & y_vel, int vel, int max_vel, int & window_x, int & window_y){
    sprite.move(x_vel, y_vel);
    x_vel += (y_vel == 0)? vel : 0;
    y_vel += (x_vel == 0)? vel : 0;
    if(x_vel < 0 && x_vel <= max_vel ||
            x_vel > 0 && x_vel >= max_vel){x_vel = max_vel;}
    if(y_vel < 0 && y_vel <= max_vel ||
            y_vel > 0 && y_vel >= max_vel){y_vel = max_vel;}
}

void stop_sprite_x(sf::Sprite & sprite, int & x_vel, int accel, int & window_x){
    x_vel += x_vel * accel;
    sprite.move(x_vel, 0);
    x_vel = 0;
}

void stop_sprite_y(sf::Sprite & sprite, int & y_vel, int accel, int & window_y){
    y_vel += y_vel * accel;
    sprite.move(0, y_vel);
    //if(sprite.getPosition().y <= window_y){sprite.setPosition(sprite.getPosition().x, window_y);}
    y_vel = 0;
} 


