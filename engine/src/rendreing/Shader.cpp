#include "rendreing/Shader.h"
#include "glad/glad.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char *vertexShaderSource = vertexCode.c_str();
    const char *fragmentShaderSource = fragmentCode.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // checkSuccess(GL_COMPILE_STATUS, vertexShader, GL_FRAGMENT_SHADER);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    // checkSuccess(GL_COMPILE_STATUS, fragmentShader, GL_FRAGMENT_SHADER);

    shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, vertexShader);
    glAttachShader(shaderProgramId, fragmentShader);
    glLinkProgram(shaderProgramId);

    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgramId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    // checkSuccess(GL_LINK_STATUS, shaderProgramId, -1);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() { glDeleteProgram(shaderProgramId); }

bool Shader::checkSuccess(int status, unsigned int shader, int type)
{
    glGetProgramiv(shader, status, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader, 512, NULL, infoLog);
        switch (type)
        {
        case GL_FRAGMENT_SHADER:
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
            break;
        case GL_VERTEX_SHADER:
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
            break;
        default:
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << infoLog << std::endl;
            break;
        }
        return false;
    }
    return true;
}

void Shader::use() { glUseProgram(shaderProgramId); }
void Shader::setBool(const char *name, bool value) const { glUniform1i(glGetUniformLocation(shaderProgramId, name), value); }
void Shader::setInt(const char *name, int value) const { glUniform1i(glGetUniformLocation(shaderProgramId, name), value); }
void Shader::setIntArray(const char *name, int size, int *value) const { glUniform1iv(glGetUniformLocation(shaderProgramId, name), size, value); }
void Shader::setFloat(const char *name, float value) const { glUniform1f(glGetUniformLocation(shaderProgramId, name), value); }
void Shader::setMat4(const char *name, float *value) const { glUniformMatrix4fv(glGetUniformLocation(shaderProgramId, name), 1, GL_FALSE, value); }