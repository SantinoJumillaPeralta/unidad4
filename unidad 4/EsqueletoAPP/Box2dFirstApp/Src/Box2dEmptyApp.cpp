#include "Game.h"
#include <tchar.h>
#include <Box2D/Box2D.h>


using namespace sf;

class Cannon {
private:
	b2Body* cannonBody; // Cuerpo del ca��n en Box2D
	RenderWindow* window; // Ventana de renderizado
	float power; // Potencia del disparo
public:
	Cannon(b2World* world, RenderWindow* wnd);
	void update(sf::Vector2f mousePosition);
	void shoot();
};

class Pelota
{

private:
	// Sprite y su imagen la para representaci�n gr�fica
	Sprite* _sprite;
	Texture* _image;
	RenderWindow* wnd;
	// Body para representaci�n f�sica
	b2Body* _body;
	//...
public:
	Pelota(b2World* _world, RenderWindow* _wnd)
	{
		// Guardamos puntero a ventana para dibujar luego
		wnd = _wnd;
		_image = new Texture();
		_image->loadFromFile("pelota.jpg");
		// Cargamos el sprite
		_sprite = new Sprite(*_image);

		// Definimos el body y lo creamos
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(100.0f, 0.0f);
		_body = _world->CreateBody(&bodyDef);

		// Creamos su figura de colisi�n
		// en este caso suponemos que la figura de
		// colision es una caja cuadrada
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(20.0f, 20.0f);

		// Creamos el fixture, le seteamos
		// la figura de colision
		// y agregamos el fixture al body
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 10.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 1.0f;
		_body->CreateFixture(&fixtureDef);
	}

	// Metodo que posiciona el sprites
	// segun la posicion del body
	void ActualizarPosiciones()
	{
		b2Vec2 pos = _body->GetPosition();
		_sprite->setPosition(pos.x, pos.y);
	}

	// Metodo que dibuja el sprite
	void Dibujar()
	{
		wnd->draw(*_sprite);
	}

	// Otros metodos
	// relacionados al personaje
};


int _tmain(int argc, _TCHAR* argv[])
{
	Game* Juego;
	Juego = new Game(800, 600, "Esqueleto de Aplicaci�n - MAVII");
	Juego->Loop();

	return 0;
}