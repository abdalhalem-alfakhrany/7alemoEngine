#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include <iostream>

Window::Window(int width, int height, const char *title)
    : width(width), hieght(height), title(title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    windowPtr = glfwCreateWindow(width, height, title, NULL, NULL);
    if (windowPtr == NULL)
    {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(windowPtr);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return;
    }
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    glfwDestroyWindow(windowPtr);
    glfwTerminate();
}

bool Window::isOpen() { return !glfwWindowShouldClose(windowPtr); }
void Window::render() { glfwSwapBuffers(windowPtr); }
void Window::update() { glfwPollEvents(); }

bool Window::getKey(int keyCode) { return glfwGetKey(windowPtr, keyCode); }
void Window::getMousePosition(double *x, double *y) { glfwGetCursorPos(windowPtr, x, y); }
bool Window::getMouseButton(int button) { return glfwGetMouseButton(windowPtr, button); }