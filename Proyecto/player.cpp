#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Player : public Drawable
{
public:
    Player(int positionx, int positiony, string textureSourcePath){
        //Texture texturePlayer;
        texturePlayer.loadFromFile(textureSourcePath);
        player.setPosition(positionx,positiony);
        player.setTexture(texturePlayer);
        //Se hace regla de 3 para sacar escala para los valores declarados arriba:
        //((dimesionEnPixelesDeseada)/TamañoPx(textura.getSize())*escalaActual(1)= nuevaEscala)
        player.setScale(playerSizeX/texturePlayer.getSize().x,playerSizeY/texturePlayer.getSize().y);
    }
    ~Player(){
        cout << "El objeto se deberia borrar" << endl;
    }
    void draw(RenderTarget &target, RenderStates states) const override
    {
        target.draw(player,states);
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


