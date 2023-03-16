#ifndef GLWindow_H
#define GLWindow_H

#include <iostream>
#include <map>
#include <math.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "../glad/include/glad/glad.h"

//#include <GL/gl.h>
//#include <GLES3/gl3.h>
#include <glm/glm.hpp>

#include "clock.hpp"
#include "glr.hpp"
#include "glwman.h"

using namespace glr;

GLuint const 
WIDTH_DEFAULT  = 320,
HEIGHT_DEFAULT = 200;

GLchar const * const
TITLE_DEFAULT = "GLWindow";

class GLWindow {

    private:      

    public:
        GLFWwindow
        * __window;  
		
        std::map< CStr, GLProject * >
		projects;

		Str
		currentProject;

		ViewControlData
		viewControlData;

    public:

        GLWindow(
            GLuint const & p_width = WIDTH_DEFAULT,
            GLuint const & p_height = HEIGHT_DEFAULT,
            GLchar const * const & p_title = TITLE_DEFAULT);

        ~GLWindow();

        int
        initGL(
            GLuint const & p_width = WIDTH_DEFAULT,
            GLuint const & p_height = HEIGHT_DEFAULT,
            GLchar const * const & p_title = TITLE_DEFAULT);

        void
        addGLProject(GLProject * p_glProject);

        void
        cleanup();
        
        void
        cursor_position(double p_xpos, double p_ypos);
        
        void
        exec();

        void
        fb_resize(int p_width, int p_height);

        void
        key(int p_key, int p_scancode, int p_action, int p_mods);
        
        void
        mouse_button(int p_button, int p_action, int p_mods);

        void
        paintGL();

        void
        removeGLProject(CStr & p_name);

        void
        selectProject(CStr & p_projectName);

        void
        scroll_wheel(double p_xoffset, double p_yoffset);

        void
        win_resize(int p_width, int p_height);
};

#endif