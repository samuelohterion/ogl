#ifndef OGL_H
#define OGL_H

#include <iostream>
#include <map>
#include <math.h>

#include "../glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GLES3/gl3.h>
#include <glm/glm.hpp>

#include "clock.hpp"
#include "glr.hpp"

using namespace glr;

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

		std::map< CStr, GLProject * >
		projects;

		CStr
		currentProject;

		ViewControlData
		viewControlData;

    public:

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
        cursor_position_callback(GLFWwindow* p_window, double p_xpos, double p_ypos);
        
        static void
        mouse_button_callback(GLFWwindow * p_window, int p_button, int p_action, int p_mods);

        static void
        scroll_callback(GLFWwindow * p_window, double p_xoffset, double p_yoffset);

        static void
        key_callback(GLFWwindow * p_window, int p_key, int p_scancode, int p_action, int p_mods);
        
        static void
        framebufferSizeCallback(GLFWwindow* p_window, int p_width, int p_height);
};

#endif