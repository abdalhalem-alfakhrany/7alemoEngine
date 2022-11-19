#pragma once
#include "rendreing/Texture.h"
#include "math/math.h"

class GameObject
{
private:
    Texture *texture;
    Vector2f m_Position;
    Vector2f m_Size;

public:
    GameObject();
    ~GameObject();

    float *getVerteciesData();

    void setPosition(Vector2f);
    void setSize(Vector2f);

    Vector2f getPosition();
    Vector2f getScale();

    Texture *getTexture() { return texture; };
    void setTexture(Texture *texture) { this->texture = texture; };
};
