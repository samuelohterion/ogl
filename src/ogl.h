#ifndef OGL_H
#define OGL_H

#include <iostream>
#include <math.h>

#include "../glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GLuint const 
WIDTH_DEFAULT  = 320,
HEIGHT_DEFAULT = 200;

GLchar const * const
TITLE_DEFAULT = "OGL";

class OGL {

    private:

        GLFWwindow
        * __window;

    public:

/*        OGL() {

            initGL();
        }
*/
        OGL(
            GLuint const & p_width = WIDTH_DEFAULT,
            GLuint const & p_height = HEIGHT_DEFAULT,
            GLchar const * const & p_title = TITLE_DEFAULT);

        ~OGL();

        int
        initGL(
            GLuint const & p_width = WIDTH_DEFAULT,
            GLuint const & p_height = HEIGHT_DEFAULT,
            GLchar const * const & p_title = TITLE_DEFAULT);

        void
        exec();

        void
        cleanup();
        
        static void
        key_callback(GLFWwindow* p_window, int p_key, int p_scancode, int p_action, int p_mods);
        
        static void
        framebufferSizeCallback(GLFWwindow* window, int p_width, int p_height);
};

#endif