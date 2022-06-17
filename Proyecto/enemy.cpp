#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Enemy
{
public:
    Enemy(int positionx, int positiony, string textureSourcePath, sf::RenderWindow &window){
        cout << "Window?" << &window << endl;
        //Texture textureEnemy;
        textureEnemy.loadFromFile(textureSourcePath);
        textureEnemy.setSmooth(true);
        enemy.setPosition(positionx,positiony);
        enemy.setTexture(textureEnemy);
        //Se hace regla de 3 para sacar escala para los valores declarados arriba:
        //((dimesionEnPixelesDeseada)/TamañoPx(textura.getSize())*escalaActual(1)= nuevaEscala)
        enemy.setScale(enemySizeX/textureEnemy.getSize().x,enemySizeY/textureEnemy.getSize().y);
        window.draw(enemy);
    }
    ~Enemy(){
        cout << "El objeto se deberia borrar" << endl;
    }

    void attack(Vector2<int> &direction){

    }
    void moveTo(float x ,float y,sf::RenderWindow &window){
        cout << x << " moviendo " << y << endl;
        enemy.move(x,y);
        window.draw(enemy);
        cout << "get()" << enemy.getPosition().y << endl;
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
        window.draw(enemy);
    }
private:
    Texture textureEnemy;
    Sprite enemy;
    float enemySizeX = 100, enemySizeY = 100, speed;
    int health = 10; 
};


