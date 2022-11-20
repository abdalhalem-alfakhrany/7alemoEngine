#pragma once
#include "GameObject.h"
#include "rendreing/Shader.h"
#include "rendreing/Texture.h"

#include <vector>

class Rendrer
{
private:
    unsigned int VAO, VBO, EBO;
    Shader *shader;

public:
    Rendrer();
    ~Rendrer();

    void render(std::vector<GameObject *> *gameObjects, std::vector<Texture *> *textures);
};
