#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(windowPtr, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return;
    }
    glViewport(0, 0, width, height);
}

Window::~Window()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(windowPtr);
    glfwTerminate();
}

bool Window::isOpen() { return !glfwWindowShouldClose(windowPtr); }
void Window::render()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(windowPtr);
}
void Window::update()
{
    glfwPollEvents();
    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

bool Window::getKey(int keyCode) { return glfwGetKey(windowPtr, keyCode); }
void Window::getMousePosition(double *x, double *y) { glfwGetCursorPos(windowPtr, x, y); }
bool Window::getMouseButton(int button) { return glfwGetMouseButton(windowPtr, button); }