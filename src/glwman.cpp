#ifndef GLWMAN_CPP
#define GLWMAN_CPP

#include <map>
//#include <GLFW/glfw3.h>
#include "glwindow.h"
#include "glwman.h"

GLWMan *
GLWMan::instance = nullptr; 

GLWMan::GLWMan() {
} 

GLWMan::~GLWMan() {

    if(instance != nullptr) {
    
        delete instance;
    }            
}

GLWMan *
GLWMan::getInstance() {

    if(instance == nullptr) {

        instance = new GLWMan();
    }

    return instance;
}

void 
GLWMan::addWindow(GLWindow * p_glWindow) {

    windows[p_glWindow -> __window] = p_glWindow;
}

void 
GLWMan::deleteWindow(GLFWwindow * p_glf_window) {

    windows.erase(p_glf_window);
}

void 
GLWMan::deleteWindow(GLWindow * p_gl_window) {

    windows.erase(p_gl_window -> __window);
}    

void
GLWMan::setBindings(GLFWwindow * p_window) {
    
    if (windows.find(p_window) != windows.end()) {

        glfwSetWindowSizeCallback(p_window, window_resize_callback);
        glfwSetFramebufferSizeCallback(p_window, framebuffer_resize_callback);
        glfwSetKeyCallback(p_window, key_callback);
        glfwSetCursorPosCallback(p_window, cursor_position_callback);
        glfwSetMouseButtonCallback(p_window, mouse_button_callback);
        glfwSetScrollCallback(p_window, scroll_wheel_callback);
    }
}

GLWindow *
GLWMan::getGLWindow(GLFWwindow * p_window) {
    
    GLWMan *
    glmwan = GLWMan::getInstance();

    std::map< GLFWwindow *, GLWindow * > &
    w = glmwan -> windows;

    return w[p_window];
}

void
GLWMan::cursor_position_callback(GLFWwindow * p_window, double p_xpos, double p_ypos) {

    GLWindow *
    glw = getGLWindow(p_window);

    if (glw != nullptr) {

        glw -> cursor_position(p_xpos, p_ypos);
    }
}

void
GLWMan::mouse_button_callback(GLFWwindow * p_window, int p_button, int p_action, int p_mods) {

    GLWindow *
    glw = getGLWindow(p_window);

    if (glw != nullptr) {

        glw -> mouse_button(p_button, p_action, p_mods);
    }
}

void
GLWMan::scroll_wheel_callback(GLFWwindow * p_window, double p_xoffset, double p_yoffset) {

    GLWindow *
    glw = getGLWindow(p_window);

    if (glw != nullptr) {

        glw -> scroll_wheel(p_xoffset, p_yoffset);
    }
}

void
GLWMan::key_callback(GLFWwindow * p_window, int p_key, int p_scancode, int p_action, int p_mods) {
    
    GLWindow *
    glw = getGLWindow(p_window);

    if (glw != nullptr) {

        glw -> key(p_key, p_scancode, p_action, p_mods);
    }
}

void
GLWMan::window_resize_callback(GLFWwindow * p_window, int p_width, int p_height) {
    
    GLWindow *
    glw = getGLWindow(p_window);

    if (glw != nullptr) {

        glw -> win_resize(p_width, p_height);
    }
}

void
GLWMan::framebuffer_resize_callback(GLFWwindow * p_window, int p_width, int p_height) {
    
    GLWindow *
    glw = getGLWindow(p_window);

    if (glw != nullptr) {

        glw -> fb_resize(p_width, p_height);
    }
}
#endif