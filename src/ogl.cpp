#include "ogl.h"

/*
OGL::OGL() {

    initGL();
}
*/

OGL::OGL(GLuint const & p_width, GLuint const & p_height, GLchar const * const & p_title) {

    initGL(p_width, p_height, p_title);
}

OGL::~OGL() {

    cleanup();
}



int
OGL::initGL(GLuint const & p_width, GLuint const & p_height, GLchar const * const & p_title) {

    if (! glfwInit()) {

        std::cout << "glfwInit() failed! Exit with error code -1." << std::endl;

        return -1;
    }

    __window = glfwCreateWindow(p_width, p_height, p_title, NULL, NULL);

    glfwMakeContextCurrent(__window);


    if (! gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {

        std::cout << "Loading GL via glad failed! Exit with error code -1." << std::endl;

        glfwTerminate();

        return -1;
    }

    glfwSetFramebufferSizeCallback(__window, framebufferSizeCallback);
    glfwSetKeyCallback(__window, key_callback);
    
    glClearColor(.25f, .5f, .75f, 1.f);

    return 0;
}

void
OGL::exec() {

    while (! glfwWindowShouldClose(__window)) {

        double
        time = glfwGetTime();

        glfwPollEvents();

        glClearColor(.25f, .5f, .5 + .5 * sin(time), 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(__window);
    }
}

void
OGL::cleanup() {

    glfwTerminate();

    glfwDestroyWindow(__window);
}

void
OGL::key_callback(GLFWwindow* p_window, int p_key, int p_scancode, int p_action, int p_mods) {
    
    if (p_key == GLFW_KEY_ESCAPE && p_action == GLFW_PRESS) {
        
        glfwSetWindowShouldClose(p_window, GLFW_TRUE);
    }
}

void
OGL::framebufferSizeCallback(GLFWwindow* p_window, int p_width, int p_height) {
    
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, p_width, p_height);
}
