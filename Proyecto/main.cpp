#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Audio/Music.hpp>
#include "player.cpp"
#include "background.cpp"
#include "enemy.cpp"
#include <iostream>
using namespace sf;
using namespace std;  

int main(void){
    //Set Window---------------------------------------------------------------------
    /*Esto de la relacion se hace para que
    el programa no varie cuando se cambia 
    la resolucion*/ 

    float actualResolution[2] = {1080,720}; // resolucion actual
    int baseResolution[2] = {1080,720}; // resolucion base sobre la que se construyó el programa
    int aspectRatioX = (baseResolution[0]/actualResolution[0]); // relacion de la pantalla en x
    int aspectRatioY = (baseResolution[1]/actualResolution[1]); // relacion de la pantalla en y
    int aspectRelation[2] = {aspectRatioX,aspectRatioY};  // se guarda los valores en un array
 
    RenderWindow window;
    window.create(VideoMode(actualResolution[0], actualResolution[1]), "Game");
    window.clear(Color::Red);
    window.setVerticalSyncEnabled(true); // Los fps se sincronizan con los de la pantalla
    //window.setFramerateLimit(60);
    Clock clock;
    clock.getElapsedTime();
    Time timer;
    timer.asSeconds(); 
    Background background("Resources/Textures/Environment/room.png", window);
    Player player(100,100,"Resources/Textures/Player/test.png",window);
    float stepMove = 10.f, stepAceleration = 10.f; 
    Enemy enemy(400,400,"Resources/Textures/Enemies/pythonBlue1.png",window);
    Music backgroundMusic;
    if (!backgroundMusic.openFromFile("Resources/Music/QuincasMoreira-Robot City.ogg")){
        return -1; // error
    }else{
        backgroundMusic.setVolume(5.0f);
        backgroundMusic.play();
    }
    window.display();
    //Events---------------------------------------------------------------------
    Event event; //Se crea el evento principal
    while (window.isOpen()){
        timer = clock.getElapsedTime();
        //cout << (int)timer.asSeconds() << endl;     
        window.clear();
        background.draw(window);
        player.draw(window);
        enemy.draw(window);
        while (window.pollEvent(event)){ //Se inicia el MAINLOOP
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
            }   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // left key is pressed: move our character
                player.moveTo(0.f, -stepMove, window);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // left key is pressed: move our character
                player.moveTo(0.f, stepMove, window);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // left key is pressed: move our character
                player.moveTo(stepMove, 0.f, window);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                // left key is pressed: move our character
                player.moveTo(-stepMove, 0.f, window);
            }
        }
        x = Player::acelerationPhysics(x);
        y = Player::acelerationPhysics(y);
        player.move(x,y);
        window.display();
    }
}

