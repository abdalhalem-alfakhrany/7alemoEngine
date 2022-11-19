#include "rendreing/Texture.h"
#include "glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static int texN = 0;

Texture::Texture(const char *texturePath)
{
    textureNumber = texN;
    glGenTextures(1, &textureId);

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
    if (data)
    {
        if (nrChannels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load " << texturePath << std::endl;
    }
    stbi_image_free(data);
    glActiveTexture(GL_TEXTURE0 + texN);
    glBindTexture(GL_TEXTURE_2D, textureId);
    texN += 1;
}

Texture::~Texture() {}