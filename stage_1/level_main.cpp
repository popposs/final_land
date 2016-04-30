#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "keyboard.cpp"

using namespace std;

//global variables
int window_x = 1000;
int window_y = 650;

sf::Event event; 
sf::RenderWindow window(sf::VideoMode(window_x, window_y), "Stage_1");

sf::Sprite player;
std::vector<sf::Sprite> mobs;
sf::Texture player_texture;
sf::Texture mob_texture;   
int x_vel = 0;
int y_vel = 0;

//updates canvas
void draw_all(){
    window.clear(sf::Color(9,9,9,255));
    window.draw(player);
    for (size_t i = 0; i < mobs.size(); i++){
    	window.draw(mobs[i]);}
    window.display();
}

//initializes square (user)
void initialize_player(){
    player_texture.loadFromFile("player1.png");
    player.setTexture(player_texture);
    player.setPosition(100, 540);
}

void initialize_mobs(){
    mob_texture.loadFromFile("mob.png");

    for(int i = 0; i < 5; i++){
        sf::Sprite mob(mob_texture);
        mob.setPosition(rand() % 10, 450);
        mobs.push_back(mob);}
}

//checks for system events
void system_events(){
    if(event.type == sf::Event::Closed){window.close();}

    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
        window.close();}
}

//keyboard inputs (pressed)
void key_pressed_events(){
    if(event.key.code == sf::Keyboard::Left){
        move_sprite(player, x_vel, y_vel, -2,0, -5, window_x, window_y);}

    else if(event.key.code == sf::Keyboard::Right){
        move_sprite(player, x_vel, y_vel, 2,0, 5, window_x, window_y);}

    else if(event.key.code == sf::Keyboard::Down){
        move_sprite(player, x_vel, y_vel,0, 2, 5, window_x, window_y);}
 
    else if(event.key.code == sf::Keyboard::Up){
        move_sprite(player, x_vel, y_vel,0, -2,- 5, window_x, window_y);}
}

//keyboard inputs (release)
void key_released_events(){
    
   if(event.key.code == sf::Keyboard::Left){
        stop_sprite_x(player, x_vel, .5, window_x);}

   else if(event.key.code == sf::Keyboard::Right){
        stop_sprite_x(player, x_vel, .5, window_x);}

   else if(event.key.code == sf::Keyboard::Up){
        stop_sprite_y(player, y_vel, .5, window_y);}
 
   else if(event.key.code == sf::Keyboard::Down){
        stop_sprite_y(player, y_vel, .5, window_y);} 
        
}

//main function
int main(){
    srand(time(NULL));
    initialize_player();
    initialize_mobs();

    while(window.isOpen()){
        event = sf::Event();

        while(window.pollEvent(event)){
            system_events();

            if(event.type == sf::Event::KeyPressed){
                key_pressed_events();}
            if(event.type == sf::Event::KeyReleased){
                key_released_events();}
            }

            draw_all();
    }
    return EXIT_SUCCESS;
};


