#pragma once
#include "rendreing/Texture.h"
#include "math/math.h"

class GameObject
{
private:
    Texture *m_Texture;
    Vector2f m_Position;
    Vector2f m_Size;

public:
    GameObject();
    ~GameObject();

    float *getVerteciesData();

    void setPosition(Vector2f);
    void setSize(Vector2f);

    Vector2f getPosition();
    Vector2f getSize();

    Texture *getTexture();
    void setTexture(Texture *texture);
};
