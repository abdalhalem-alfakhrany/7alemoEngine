#pragma once
#include <iostream>

class Texture
{
private:
    unsigned int textureId;
    unsigned int textureNumber;

public:
    Texture(const char *texturePath);
    ~Texture();

    unsigned int getTextureNumber();
    unsigned int getTextureId();
};
