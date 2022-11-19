struct GLFWwindow;
struct Vector2f;

class Window
{
private:
    int width;
    int hieght;
    const char *title;
    GLFWwindow *windowPtr;

public:
    Window(int width, int hieght, const char *title);
    ~Window();

    bool isOpen();
    void render();
    void update();

    bool getKey(int keyCode);
    void getMousePosition(double *x,double *y);
    bool getMouseButton(int button);
};
