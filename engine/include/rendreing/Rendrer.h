#pragma once
#include "GameObject.h"
#include <vector>
class Shader;
class Rendrer
{
private:
    unsigned int VAO, VBO, EBO;
    Shader *shader;

public:
    Rendrer();
    ~Rendrer();

    void render(std::vector<GameObject*> *gameObjects);
};
