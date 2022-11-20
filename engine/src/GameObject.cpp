#include "GameObject.h"

GameObject::GameObject(){};

GameObject::~GameObject()
{
    printf("game object %p deleted yastaaaaa!\n", this);
};

void GameObject::setPosition(Vector2f position) { m_Position = position; }
void GameObject::setSize(Vector2f size) { m_Size = size; }
void GameObject::setTexture(Texture *texture) { m_Texture = texture; };

Vector2f GameObject::getPosition() { return m_Position; }
Vector2f GameObject::getSize() { return m_Size; }
Texture *GameObject::getTexture() { return m_Texture; };