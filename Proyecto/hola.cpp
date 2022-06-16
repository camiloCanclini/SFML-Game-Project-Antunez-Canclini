#include "hola.h"

juego::juego (int resolucion_x, int resolucion_y, string titulo)
{
	fps = 60;

	evento1 = new Event; //Los eventos son utilizados para que podamos manejarnos con el teclado o el mouse

	ventana1 = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);

	ventana1->setFramerateLimit(fps); //Para que el programa corra a esa velocidad

	ventana1->setMouseCursorVisible(false);

	reloj1 = new Clock();
	tiempo1 = new Time();


	//-----------------------------------------------------------------------------------//
	//									R O O M

	txt_room = new Texture;
	room = new Sprite;
	txt_room->loadFromFile("sprites/room.png");
	room->setTexture(*txt_room);
	room->setScale(((float)ventana1->getSize().x / (float) room->getTexture()->getSize().x), ((float) ventana1->getSize().y / (float) room->getTexture()->getSize().y));

	//rellenar toda la pantalla
	room->setScale(50, 50);

	//Tama�o del sprite
	room->setScale(800.f / room->getTexture()->getSize().x, 600.f / room->getTexture()->getSize().y); //dimension deseada / el tama�o actual

	//----------------------------------------------------------------------------------//
	//								P R O T A G O N I S T

	textura1 = new Texture;
	sprites1 = new Sprite;
	textura1->loadFromFile("sprites/2.png");
	sprites1->setTexture(*textura1);
	sprites1->setPosition(100, 100);

	//asignar la posicion media del sprite para una mejor rotacion
	sprites1-> setOrigin(sprites1->getTexture()->getSize().x / 2.f, sprites1->getTexture()->getSize().y / 2.f);
	
	//color del sprite
	//sprites1->setColor(Color::Magenta);

	//Tama�o del sprite
	sprites1->setScale(50.f / sprites1->getTexture()->getSize().x, 50.f / sprites1->getTexture()->getSize().y); //dimension deseada / el tama�o actual

	//rellenar toda la pantalla
	//sprites1->setScale(((float)ventana1->getSize().x / (float)sprites1->getTexture()->getSize().x), ((float)ventana1->getSize().y / (float)sprites1->getTexture()->getSize().y));

	//----------------------------------------------------------------------------------//
	//								E N E M I E S
	
	enemigo = new Sprite;
	enemigo->setTexture(*textura1);
	enemigo->setPosition(400, 300);
	enemigo->setColor(Color::Green);
	enemigo->setScale(50.f / enemigo->getTexture()->getSize().x, 50.f / enemigo->getTexture()->getSize().y);


	//----------------------------------------------------------------------------------//
	//	

	cofre = new RectangleShape({ 64,64 });
	txt_cofre = new Texture;
	txt_cofre->loadFromFile("sprites/cofre.png");
	cofre->setTexture(txt_cofre);
	cofre->setPosition(300, 300);




	gameLoop();


}

void juego::dibujarVentana() 
{
	ventana1-> clear(); //Te limpia la ventana

	ventana1->draw(*room);

	ventana1->draw(*cofre);

	ventana1->draw(*sprites1); //muestra el sprite

	ventana1->draw(*enemigo);

	ventana1-> display(); //Te muestra la ventana



}

//Funcion para que la ventana este abierta hasta que el usuario lo desee.
void juego::gameLoop()
{
	while (ventana1 -> isOpen())
	{
		//sprites1->setRotation(sprites1->getRotation()+3);
		procesar_eventos();
		procesar_colisiones();
		procesar_mouse();
		dibujarVentana();
		*tiempo1 = reloj1->getElapsedTime();
		cout << tiempo1->asSeconds() << endl;
	}
}

//Funcion donde se manejan los eventos necesarios
void juego::procesar_eventos()
{
	while (ventana1->pollEvent(*evento1))
	{
		switch (evento1 -> type)
		{

		case Event::Closed:
			ventana1->close();
			exit(1);
			break;

		case Event::KeyPressed:

			if (Keyboard::isKeyPressed(Keyboard::C))
			{
				exit(1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W))
			{
				sprites1->setPosition(sprites1->getPosition().x, sprites1->getPosition().y - 5);
			}
			else if (Keyboard::isKeyPressed(Keyboard::S))
			{
				sprites1->setPosition(sprites1->getPosition().x, sprites1->getPosition().y + 5);
			}
			else if (Keyboard::isKeyPressed(Keyboard::A))
			{
				sprites1->setPosition(sprites1->getPosition().x - 5, sprites1->getPosition().y);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				sprites1->setPosition(sprites1->getPosition().x + 5, sprites1->getPosition().y);
			}
			break;


		case Event::MouseButtonPressed:
		
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				
			}
		

		}
		
	}
}

void juego::procesar_mouse()
{

	posicion_mouse = Mouse::getPosition(*ventana1); //posicion relativa a la ventana del juego
	posicion_mouse = (Vector2i)ventana1->mapPixelToCoords(posicion_mouse);

}

void juego::procesar_colisiones()

{
	if (sprites1->getGlobalBounds().intersects(enemigo->getGlobalBounds()))
	{
		sprites1->setColor(Color::Red);
	}
	else
		sprites1->setColor(Color::White);

}