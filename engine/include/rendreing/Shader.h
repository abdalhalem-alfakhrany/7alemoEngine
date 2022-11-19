#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
class Shader
{
public:
    unsigned int shaderProgramId;
    int success;
    char infoLog[512];

    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();

    void use();

    void setBool(const char *name, bool value) const;
    void setInt(const char *name, int value) const;
    void setIntArray(const char *name, int size, int *value) const;
    void setFloat(const char *name, float value) const;
    void setMat4(const char *name, float *value) const;

    bool checkSuccess(int status, unsigned int shader, int type);
};
