#include "glad/glad.h"
#include "rendreing/Rendrer.h"
#include "rendreing/Shader.h"
#include "math/math.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

Rendrer::Rendrer()
{
    printf("rendrer init \n");
    shader = new Shader("resources/shaders/vertex.glsl", "resources/shaders/fragment.glsl");
    int strideSize = 6 * sizeof(float);

    unsigned int indices[100 * 6];
    for (int i = 0; i < 100; i++)
    {
        indices[0 + i * 6] = 0 + i * 4;
        indices[1 + i * 6] = 1 + i * 4;
        indices[2 + i * 6] = 2 + i * 4;
        indices[3 + i * 6] = 1 + i * 4;
        indices[4 + i * 6] = 2 + i * 4;
        indices[5 + i * 6] = 3 + i * 4;
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glEnable(GL_BLEND);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 100 * 4 * strideSize, nullptr, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, strideSize, (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, strideSize, (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, strideSize, (void *)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    shader->use();

    int textures[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    shader->setIntArray("textures", 9, textures);

    glm::mat4 projection, viewMatrix;
    glm::vec3 cameraFront, cameraUp;
    glm::vec2 cameraPosition(0.0f, 0.0f);

    projection = glm::ortho(0.0f, 640.0f, 640.0f, 0.0f, -1.0f, 1.0f);
    shader->setMat4("projection", &projection[0][0]);

    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    viewMatrix = glm::lookAt(
        glm::vec3(cameraPosition.x, cameraPosition.y, 0.0f),
        cameraFront + glm::vec3(cameraPosition.x, cameraPosition.y, 0.0f),
        cameraUp);
    shader->setMat4("view", &viewMatrix[0][0]);
}

Rendrer::~Rendrer()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    delete shader;
}

void Rendrer::render(std::vector<GameObject *> *gameObjects, std::vector<Texture *> *textures)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // float vertices[] = {
    //     100,100,0, 0,0,0,
    //     200,100,0, 1,0,0,
    //     100,200,0, 0,1,0,
    //     200,200,0, 1,1,0,
    // };

    for (int i = 0; i < textures->size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + textures->at(i)->getTextureNumber());
        glBindTexture(GL_TEXTURE_2D, textures->at(i)->getTextureId());
    }

    float *vertices = new float[2 * 6 * 4];

    for (int i = 0; i < gameObjects->size(); i++)
    {
        Vector2f position = gameObjects->at(i)->getPosition();
        Vector2f size = gameObjects->at(i)->getSize();
        float texture = gameObjects->at(i)->getTexture()->getTextureNumber();

        vertices[0 + i * 24] = position.x;
        vertices[1 + i * 24] = position.y;
        vertices[2 + i * 24] = 0.0f;
        vertices[3 + i * 24] = 0.0f;
        vertices[4 + i * 24] = 0.0f;
        vertices[5 + i * 24] = texture;

        vertices[0 + 6 + i * 24] = position.x + size.x;
        vertices[1 + 6 + i * 24] = position.y;
        vertices[2 + 6 + i * 24] = 0.0f;
        vertices[3 + 6 + i * 24] = 1.0f;
        vertices[4 + 6 + i * 24] = 0.0f;
        vertices[5 + 6 + i * 24] = texture;

        vertices[0 + 12 + i * 24] = position.x;
        vertices[1 + 12 + i * 24] = position.y + size.y;
        vertices[2 + 12 + i * 24] = 0.0f;
        vertices[3 + 12 + i * 24] = 0.0f;
        vertices[4 + 12 + i * 24] = 1.0f;
        vertices[5 + 12 + i * 24] = texture;

        vertices[0 + 18 + i * 24] = position.x + size.x;
        vertices[1 + 18 + i * 24] = position.y + size.y;
        vertices[2 + 18 + i * 24] = 0.0f;
        vertices[3 + 18 + i * 24] = 1.0f;
        vertices[4 + 18 + i * 24] = 1.0f;
        vertices[5 + 18 + i * 24] = texture;
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, gameObjects->size() * 6 * 4 * sizeof(float), vertices);

    shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, gameObjects->size() * 6, GL_UNSIGNED_INT, 0);
    delete[] vertices;
}