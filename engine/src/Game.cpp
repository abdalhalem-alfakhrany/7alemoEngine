#include "glad/glad.h"
#include "Game.h"
#include "GameObject.h"
#include "rendreing/Rendrer.h"
#include "math/math.h"

#include "imgui.h"

Game::Game(int width, int height, const char *title)
{
    printf("game init \n");
    window = new Window(width, height, title);
    rendrer = new Rendrer();
}

Game::~Game()
{
    delete rendrer;
    delete window;
}

void Game::addObject(GameObject *gameObject)
{
    printf("game object added ptr : %p\n", gameObject);
    gameObjects.push_back(gameObject);
}

void Game::removeObject(GameObject *gameObject)
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (gameObject == gameObjects[i])
        {
            printf("game object removed ptr : %p\n", gameObject);
            gameObjects.erase(gameObjects.begin() + i);
            delete gameObject;
            return;
        }
    }
}

void Game::addTexture(Texture *texture)
{
    textures.push_back(texture);
}

void Game::removeTexture(Texture *texture)
{
    delete texture;
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
    onImgui();
    ImGui::Render();
    rendrer->render(&gameObjects, &textures);
    window->render();
}

void Game::getMousePosition(float *x, float *y)
{
    // ايوا عارف انو عك بس عاوز اخلص
    double dx, dy;
    window->getMousePosition(&dx, &dy);
    *x = (float)dx;
    *y = (float)dy;
}

bool Game::isKeyDown(int keyCode) { return window->getKey(keyCode) == 1; }
bool Game::isKeyUp(int keyCode) { return window->getKey(keyCode) == 0; }

bool Game::isMouseButtonDown(int button) { return window->getMouseButton(button) == 1; }
bool Game::isMouseButtonUp(int button) { return window->getMouseButton(button) == 0; }