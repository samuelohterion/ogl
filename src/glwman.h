#ifndef GLWMAN_H
#define GLWMAN_H

#include <map>
#include <GLFW/glfw3.h>
//#include "glwindow.h"

class GLWindow;

class GLWMan {  
    
    
    private:
    
        static GLWMan *
        instance;
    
    public:

        std::map< GLFWwindow *, GLWindow * > 
        windows;
    
    private:

        GLWMan();
    
    public:

        ~GLWMan();

        static GLWMan *
        getInstance();

        void 
        addWindow(GLWindow * p_glWindow);

        void 
        deleteWindow(GLFWwindow * p_glf_window);

        void 
        deleteWindow(GLWindow * p_gl_window);

        void
        setBindings(GLFWwindow * p_window);

        static GLWindow *
        getGLWindow(GLFWwindow * p_window);

        static void
        cursor_position_callback(GLFWwindow * p_window, double p_xpos, double p_ypos);

        static void
        mouse_button_callback(GLFWwindow * p_window, int p_button, int p_action, int p_mods);

        static void
        scroll_wheel_callback(GLFWwindow * p_window, double p_xoffset, double p_yoffset);

        static void
        key_callback(GLFWwindow * p_window, int p_key, int p_scancode, int p_action, int p_mods);

        static void
        resize_callback(GLFWwindow * p_window, int p_width, int p_height);
};
#endif