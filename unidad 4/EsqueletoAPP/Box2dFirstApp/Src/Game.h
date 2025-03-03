#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "SFMLRenderer.h"
#include <list>
#include "Obstacle.h"

using namespace sf;

class Game
{
private:
    // Propiedades de la ventana
    int alto;
    int ancho;
    RenderWindow* wnd;
    Color clearColor;

    // Objetos de box2d
    b2World* phyWorld;
    SFMLRenderer* debugRender;

    // Tiempo de frame
    float frameTime;
    int fps;

    // Cuerpo de box2d
    b2Body* controlBody;

    // Lista de obstáculos
    std::list<Obstacle*> obstacles; // Agregamos una lista para almacenar los obstáculos

public:
    // Constructores, destructores e inicializadores
    Game(int ancho, int alto, std::string titulo);
    void CheckCollitions();
    void CreateEnemy(int x, int y);
    ~Game(void);
    void InitPhysics();

    // Main game loop
    void Loop();
    void DrawGame();
    void UpdatePhysics();
    void DoEvents();
    void SetZoom();
};
