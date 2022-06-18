#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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
 
    RenderWindow window;
    window.create(VideoMode(actualResolution[0], actualResolution[1]), "Game");
    //window.setVerticalSyncEnabled(true); // Los fps se sincronizan con los de la pantalla
    //window.setFramerateLimit(60);
    /*Clock clock;
    clock.getElapsedTime();
    Time timer;
    timer.asSeconds();
    */ 
    Background background("Resources/Textures/Environment/room.png", window);
    //Player player(100,100,"Resources/Textures/Player/test.png");
    Texture texturePlayer;
    texturePlayer.loadFromFile("Resources/Textures/Enemies/pythonBlue1.png");
    Sprite player;
    player.setTexture(texturePlayer);
    //Se hace regla de 3 para sacar escala para los valores declarados arriba:
    //((dimesionEnPixelesDeseada)/TamañoPx(textura.getSize())*escalaActual(1)= nuevaEscala)
    //player.setScale(100.f/texturePlayer.getSize().x,100.f/texturePlayer.getSize().y);
    float stepMove = 3, stepAceleration = 10.f; 
    Enemy enemy(400,400,"Resources/Textures/Enemies/pythonBlue1.png",window);
    Music backgroundMusic;

    if (!backgroundMusic.openFromFile("Resources/Music/QuincasMoreira-Robot City.ogg")){
        return -1; // error
    }else{
        backgroundMusic.setVolume(5.0f);
        backgroundMusic.play();
    }
    //Events---------------------------------------------------------------------
    Event event; //Se crea el evento principal
    while (window.isOpen()){
        //timer = clock.getElapsedTime();
        //cout << (int)timer.asSeconds() << endl;     
        while (window.pollEvent(event)){ //Se inicia el MAINLOOP
            if (event.type == Event::Closed){
                window.close();
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // left key is pressed: move our character
                player.move(0, -stepMove);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                // left key is pressed: move our character
                player.move(0, stepMove);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                // left key is pressed: move our character
                player.move(stepMove, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                // left key is pressed: move our character
                player.move(-stepMove, 0);
            }
        }
        /*x = Player::acelerationPhysics(x);
        y = Player::acelerationPhysics(y);
        player.move(x,y);*/
        
        window.clear();
        window.draw(player);
        window.display();
    }
}

