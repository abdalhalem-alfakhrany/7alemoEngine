#pragma once
#include <iostream>

class Texture
{
public:
    unsigned int textureId;
    unsigned int textureNumber;
    Texture(const char *texturePath);
    ~Texture();

    unsigned int getTextureNumber() { return textureNumber; };
};
