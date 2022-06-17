#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Audio/Music.hpp>
#include "hola.h"
#include "player.cpp"
#include "background.cpp"
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
    Background background("Resources/Textures/Environment/room.png", window);
    Player player(100,100,"Resources/Textures/Player/test.png", window);
    
    Music backgroundMusic;
    
    if (!backgroundMusic.openFromFile("Resources/Music/QuincasMoreira-Robot City.ogg"))
    return -1; // error
    backgroundMusic.play();
    //player.~Player(); 


    //Set Player---------------------------------------------------------------------
    /*
    // Se carga la textura del jugador
    int positionx=100, positiony=100;
    Texture texturePlayer;
    texturePlayer.loadFromFile("Resources/Textures/Player/test.png");
    texturePlayer.setSmooth(true);
    //Se crea el sprite del jugador
    Sprite player;
    // Tamaño en PX que tendra el jugador
    float playerSizeX = 100, playerSizeY = 100; 
    player.setPosition(positionx,positiony);
    player.setTexture(texturePlayer);
    //Se hace regla de 3 para sacar escala para los valores declarados arriba:
    //((dimesionEnPixelesDeseada)/TamañoPx(textura.getSize())*escalaActual(1)= nuevaEscala)
    player.setScale(playerSizeX/texturePlayer.getSize().x,playerSizeY/texturePlayer.getSize().y);
    */
    
    //Set Background---------------------------------------------------------------------
    /*
    Texture texturebackground;
    texturebackground.loadFromFile("Resources/Textures/Environment/room.png");
    Sprite background;
    background.setTexture(texturebackground);
    background.setScale((float)window.getSize().x/(float)texturebackground.getSize().x,(float)window.getSize().y/(float)texturebackground.getSize().y);
    */
    //Draw the first instance---------------------------------------------------------------------
    //window.draw(background);
    //jugador.draw(window);
    window.display();
    //Events---------------------------------------------------------------------
    while (window.isOpen())
    {     
        Event event; //Se crea el evento principal
        while (window.pollEvent(event)) //Se inicia el MAINLOOP
        {
            if (event.type == Event::Closed)
                window.close();
        }
    }
}

