#include <SFML/Graphics.hpp>
//#include <string.h>
using namespace sf;
using namespace std;

class Player
{
public:
    Player(int positionx, int positiony, string textureSourcePath, sf::RenderWindow &window){
        //Texture texturePlayer;
        texturePlayer.loadFromFile(textureSourcePath);
        texturePlayer.setSmooth(true);
        //Se crea el sprite del jugador
        //Sprite player;
        // Tamaño en PX que tendra el jugador
        float playerSizeX = 100, playerSizeY = 100; 
        player.setPosition(positionx,positiony);
        player.setTexture(texturePlayer);
        //Se hace regla de 3 para sacar escala para los valores declarados arriba:
        //((dimesionEnPixelesDeseada)/TamañoPx(textura.getSize())*escalaActual(1)= nuevaEscala)
        player.setScale(playerSizeX/texturePlayer.getSize().x,playerSizeY/texturePlayer.getSize().y);
        window.draw(player);
    }
    void attack(Vector2<int> &direction){

    }
    void moveTo(float x ,float y){
        player.move(x,y);
    }
    void healthChange(int point){
        health += point;
    }
    void speedChange(float newSpeed){
        speed = newSpeed;
    }
    void collitionPhysics(){

    }
    void takeItem(int itemId){
        if(itemId == 1){

        }else{
            if(itemId == 2){

            }else{
                if(itemId == 3){

                }else{
                    
                }
            }
        } 
    }
    void die(){
        
    }
private:
    Texture texturePlayer;
    Sprite player;
    float playerSizeX = 100, playerSizeY = 100, speed;
    int health = 10; 
   
};


