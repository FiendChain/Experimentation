#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define ASSERT(x) if(!(x)) __builtin_trap();
#define GLCall(func) GLClearErrors();\
    func;\
    ASSERT(GLCheckErrors(#func, __FILE__, __LINE__))

GLFWwindow *InitGLFW(unsigned int width, unsigned int height);
bool InitGLEW();
void Start(GLFWwindow *);
void GLClearErrors();
bool GLCheckErrors(const char *, const char *, int);

int main(int argc, char *argv[]) 
{
    GLFWwindow *window;
    ASSERT(window = InitGLFW(640, 480));
    ASSERT(InitGLEW());
    Start(window);

    return 0;
}

GLFWwindow *InitGLFW(unsigned int width, unsigned int height)
{
    if (glfwInit() == GL_FALSE) {
        std::cerr << "Failed to init glfw library" << std::endl;
        return NULL;
    }
    // set opengl profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // create window with opengl context
    GLFWwindow *window = glfwCreateWindow(width, height, "OpenGL app", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        std::cerr << "Failed to create opengl window" << std::endl;
        return NULL;
    }
    // make window current context
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    return window;
}

bool InitGLEW()
{
    GLenum err = glewInit();
    if (err != GLEW_OK) 
    {
        std::cerr << "Glew init error: " << glewGetErrorString(err) << std::endl;
        return false;
    }
    return true;
}

void Start(GLFWwindow *window)
{
    while (!glfwWindowShouldClose(window)) 
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT)); 
        GLCall(glfwSwapBuffers(window)); 
        GLCall(glfwPollEvents());
    }
}

void GLClearErrors() {
    while (glGetError() != GL_NO_ERROR)
    {

    }
}
 
bool GLCheckErrors(const char *funcName, const char *file, int line) {
    while (GLenum error = glGetError())
    {
        std::cerr << "[OpenGL Error] (" << error << "): "
            << funcName << "@" << file << ":" << line << std::endl;
        return false;
    }
    return true; 
}