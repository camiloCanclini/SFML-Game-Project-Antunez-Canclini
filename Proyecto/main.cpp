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
        cout << (int)timer.asSeconds() << endl;     
        window.clear();
        background.draw(window);
        player.draw(window);
        enemy.draw(window);
        while (window.pollEvent(event)){ //Se inicia el MAINLOOP
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
                if(event.key.code == Keyboard::Up||event.key.code == Keyboard::W){
                        cout << "se esta moviendo hacia arriba" << endl;
                        player.moveTo(0.0f,-10.f,window);
                        //menuOptionSelection(1)
                        break;
                }
                case Event::KeyPressed:
                    if(event.key.code == Keyboard::Left||event.key.code == Keyboard::A){
                        cout << "se esta moviendo a la izquierda" << endl;
                        player.moveTo(-10.0f,0.0f,window);
                        break;
                    }
                    if(event.key.code == Keyboard::Right||event.key.code == Keyboard::D){
                        cout << "se esta moviendo a la derecha" << endl;
                        player.moveTo(10.0f,0.0f,window);
                        break;
                    }
                    if(event.key.code == Keyboard::Up||event.key.code == Keyboard::W){
                        cout << "se esta moviendo hacia arriba" << endl;
                        player.moveTo(0.0f,-10.f,window);
                        //menuOptionSelection(1)
                        break;
                    }
                    if(event.key.code == Keyboard::Down||event.key.code == Keyboard::S){
                        cout << "se esta moviendo hacia abajo" << endl;
                        player.moveTo(0.f,10.f,window);
                        //menuOptionSelection(-1)
                        break;
                    }
                    if(event.key.code == Keyboard::Escape){
                        cout << "Se abrió el menu" << endl;
                        break;
                    }
                    if(event.key.code == Keyboard::B){
                        cout << "Disparando" << endl;
                        break;
                    }
                    break;
            }   
        }
        window.display();
    }
}

