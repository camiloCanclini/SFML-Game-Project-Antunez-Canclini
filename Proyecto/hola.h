#include "SFML/Graphics.hpp"
#include "iostream"
using namespace sf;
using namespace std;

class juego
{

public: //Aca establecemos las funciones para que luego en SFML - base, el usuario pueda construir el juego dependiendo los parametros
	juego(int resolucion_x, int resolucion_y, string titulo);
   //Tambien se puede colocar con vector2f
	//juego(Vector2i dimension, string titulo);
	void dibujarVentana();
	void gameLoop();
	void procesar_eventos();
	void procesar_mouse();
	void procesar_colisiones();


private:

	RenderWindow* ventana1;
	int fps;

	Event * evento1;
	Vector2i posicion_mouse;

	Texture* txt_room;
	Sprite * room;

	Texture * textura1;
	Sprite * sprites1;
	Sprite * enemigo;

	Texture * txt_cofre;
	RectangleShape * cofre;

	Clock* reloj1;
	Time* tiempo1;



};