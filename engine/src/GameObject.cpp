#include "GameObject.h"

GameObject::GameObject()
{
    printf("game object init \n");
}

GameObject::~GameObject()
{
}

void GameObject::setPosition(Vector2f position) { m_Position = position; }
void GameObject::setSize(Vector2f size) { m_Size = size; }

Vector2f GameObject::getPosition() { return m_Position; }
Vector2f GameObject::getScale() { return m_Size; }