#include <vector>
#include "GameObject.h"
#include "Window.h"
#include "rendreing/Rendrer.h"

class Game
{
private:
    void render();

    std::vector<Texture *> textures;
    Rendrer *rendrer;
    Window *window;

public:
    std::vector<GameObject *> gameObjects;

public:
    Game(int width, int height, const char *title);
    ~Game();

    void run();

    void addObject(GameObject *gameObject);
    void removeObject(GameObject *gameObject);

    void addTexture(Texture *texture);
    void removeTexture(Texture *texture);

    bool isKeyDown(int keyCode);
    bool isKeyUp(int keyCode);

    void getMousePosition(float *x, float *y);
    bool isMouseButtonDown(int button);
    bool isMouseButtonUp(int button);

    void virtual onCreate() = 0;
    void virtual onDestroy() = 0;

    void virtual onImgui() = 0;

    void virtual onUpdate() = 0;
};

extern Game *getGame();

int main()
{
    Game *game = getGame();
    game->run();
    return 0;
}