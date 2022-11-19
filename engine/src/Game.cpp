#include "glad/glad.h"
#include "Game.h"
#include "GameObject.h"
#include "rendreing/Rendrer.h"
#include "math/math.h"

Game::Game(int width, int height, const char *title)
{
    printf("game init \n");
    window = new Window(width, height, title);
    rendrer = new Rendrer();
    // onCreate();
}

Game::~Game()
{
    delete rendrer;
    delete window;
}

void Game::addObject(GameObject *gameObject)
{
    printf("added object\n");
    gameObjects.push_back(gameObject);
}

void Game::removeObject(GameObject *gameObject)
{
    delete gameObject;
}

void Game::run()
{
    while (window->isOpen())
    {
        window->update();
        onUpdate();
        render();
    }
}

void Game::render()
{
    rendrer->render(&gameObjects);
    window->render();
}

void Game::getMousePosition(double *x, double *y) { window->getMousePosition(x, y); }

bool Game::isKeyDown(int keyCode) { return window->getKey(keyCode) == 1; }
bool Game::isKeyUp(int keyCode) { return window->getKey(keyCode) == 0; }

bool Game::isMouseButtonDown(int button) { return window->getMouseButton(button) == 1; }
bool Game::isMouseButtonUp(int button) { return window->getMouseButton(button) == 0; }