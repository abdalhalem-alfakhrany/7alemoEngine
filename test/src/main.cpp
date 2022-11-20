#include "Game.h"
#include "imgui.h"

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
        delete backGroundTexture;
        delete enemySpaceShipTexture;
    };
    bool beenRelaesed = false;

    Texture *backGroundTexture;
    Texture *playerSpaceShipTexture;
    Texture *enemySpaceShipTexture;
    Texture *bulletTexture;

    GameObject *backGround;
    GameObject *playerSpaceShip;
    GameObject *enemySpaceShip;

    std::vector<GameObject *> bullets;

    void onCreate() override
    {
        backGroundTexture = new Texture("resources/textures/space_bg.jpg");
        playerSpaceShipTexture = new Texture("resources/textures/player_space_ship.png");
        bulletTexture = new Texture("resources/textures/bullet.png");
        enemySpaceShipTexture = new Texture("resources/textures/enemy_space_ship.png");

        addTexture(backGroundTexture);
        addTexture(playerSpaceShipTexture);
        addTexture(bulletTexture);
        addTexture(enemySpaceShipTexture);

        backGround = new GameObject();
        backGround->setPosition({0, 0});
        backGround->setSize({640, 640});
        backGround->setTexture(backGroundTexture);

        playerSpaceShip = new GameObject();
        playerSpaceShip->setPosition({100, 200});
        playerSpaceShip->setSize({144 * 0.65, 185 * 0.65});
        playerSpaceShip->setTexture(playerSpaceShipTexture);

        addObject(backGround);
        addObject(playerSpaceShip);
    };

    void onDestroy() override
    {
        removeObject(backGround);
        removeObject(playerSpaceShip);
    };

    void onImgui() override
    {
        ImGui::Begin("inspector");
        if (ImGui::Button("shut bullet"))
        {
            GameObject *bullet = new GameObject();
            bullet->setPosition(playerSpaceShip->getPosition());
            bullet->setSize({17 * .20, 67 * .20});
            bullet->setTexture(bulletTexture);
            bullets.push_back(bullet);
            addObject(bullet);
        }
        ImGui::End();
    }

    void onUpdate() override
    {
        for (int i = 0; i < bullets.size(); i++)
        {
            Vector2f currentPos = bullets[i]->getPosition();
            bullets[i]->setPosition({currentPos.x, currentPos.y - 7});

            if (currentPos.y < 0)
                removeObject(bullets[i]);
        }

        if (isKeyDown(256))
            exit(1);
    };
};

Game *getGame() { return new MyGame(); }