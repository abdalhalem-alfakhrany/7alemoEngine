#include "Game.h"

class MyGame : public Game
{
public:
public:
    MyGame() : Game(640, 640, "the shake7a game")
    {
        onCreate();
    };
    ~MyGame()
    {
        delete texture1;
        delete backGround;
    };

    Texture *texture1;
    GameObject *backGround;

    void onCreate() override
    {
        texture1 = new Texture("resources/textures/space_bg.jpg");

        backGround = new GameObject();

        backGround->setPosition({0, 0});
        backGround->setSize({640, 640});
        backGround->setTexture(texture1);

        addObject(backGround);
    };

    void onDestroy() override{};

    void onUpdate() override
    {
        if (isKeyDown(256))
        {
            exit(1);
        }
    };
};

Game *getGame() { return new MyGame(); }