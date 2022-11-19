#include <vector>
#include "GameObject.h"
#include "Window.h"
#include "rendreing/Rendrer.h"

class Game
{
private:
    void render();

    std::vector<GameObject *> gameObjects;
    Rendrer *rendrer;
    Window *window;

public:
    Game(int width, int height, const char *title);
    ~Game();

    void run();

    void addObject(GameObject *gameObject);
    void removeObject(GameObject *gameObject);

    bool isKeyDown(int keyCode);
    bool isKeyUp(int keyCode);

    void getMousePosition(double *x, double *y);
    bool isMouseButtonDown(int button);
    bool isMouseButtonUp(int button);

    void virtual onCreate() = 0;
    void virtual onDestroy() = 0;

    void virtual onUpdate() = 0;
};

extern Game *getGame();

int main()
{
    Game *game = getGame();
    game->run();
    return 0;
}