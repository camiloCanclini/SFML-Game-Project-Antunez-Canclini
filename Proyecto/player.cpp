#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Player
{
public:
    Player(int positionx, int positiony, string textureSourcePath, sf::RenderWindow &window){
        cout << "Window?" << &window << endl;
        //Texture texturePlayer;
        texturePlayer.loadFromFile(textureSourcePath);
        texturePlayer.setSmooth(true);
        player.setPosition(positionx,positiony);
        player.setTexture(texturePlayer);
        //Se hace regla de 3 para sacar escala para los valores declarados arriba:
        //((dimesionEnPixelesDeseada)/TamañoPx(textura.getSize())*escalaActual(1)= nuevaEscala)
        player.setScale(playerSizeX/texturePlayer.getSize().x,playerSizeY/texturePlayer.getSize().y);
        window.draw(player);
    }
    ~Player(){
        cout << "El objeto se deberia borrar" << endl;
    }

    void attack(Vector2<int> &direction){

    }
    void moveTo(float x ,float y,sf::RenderWindow &window){
        cout << x << " moviendo " << y << endl;
        player.move(x,y);
        window.draw(player);
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
    void draw(sf::RenderWindow &window){
        window.draw(player);
    }
    float acelerationPhysics(float aceleration){
        float stepAceleration = 2, maxAceleration = 40;
        if(aceleration < 0)
        {
            aceleration += stepAceleration;
        }else{
            if(aceleration > 0)
            {
                aceleration -= stepAceleration;
            }else{
                if(aceleration < -maxAceleration)
                {
                    aceleration = -maxAceleration;
                }else{
                    if(aceleration > maxAceleration)
                    {
                        aceleration = maxAceleration;
                    }else{
                        aceleration = 0;
                    }
                }
            }
        }
        return aceleration;
    }
private:
    Texture texturePlayer;
    Sprite player;
    float playerSizeX = 100, playerSizeY = 100, speed, aceleration;
    int health = 10; 
};


