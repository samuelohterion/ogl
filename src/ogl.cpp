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

        std::cout << "glfwInit() failed! Exit with error code EXIT_FAILURE." << std::endl;

        return EXIT_FAILURE;
    }

    __window = glfwCreateWindow(p_width, p_height, p_title, NULL, NULL);

    glfwMakeContextCurrent(__window);


    if (! gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {

        std::cout << "Loading GL via glad failed! Exit with error code EXIT_FAILURE." << std::endl;

        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwSetFramebufferSizeCallback(__window, framebufferSizeCallback);
    glfwSetKeyCallback(__window, key_callback);
    glfwSetCursorPosCallback(__window, cursor_position_callback);
    glfwSetMouseButtonCallback(__window, mouse_button_callback);
    glfwSetScrollCallback(__window, scroll_callback);

    glClearColor(.25f, .5f, .75f, 1.f);

    return EXIT_SUCCESS;
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

    for(auto & p : projects)

		delete p.second;

    glfwTerminate();

    glfwDestroyWindow(__window);
}

void
OGL::cursor_position_callback(GLFWwindow * p_window, double p_xpos, double p_ypos) {

    std::cout << "mouse pos: " << p_xpos << ", " << p_ypos << std::endl;
}

void
OGL::mouse_button_callback(GLFWwindow * p_window, int p_button, int p_action, int p_mods) {

    if (p_button == GLFW_MOUSE_BUTTON_LEFT && p_action == GLFW_PRESS)
        std::cout << "left mouse button pressed\n";

    if (p_button == GLFW_MOUSE_BUTTON_MIDDLE && p_action == GLFW_PRESS)
        std::cout << "middle mouse button pressed\n";

    if (p_button == GLFW_MOUSE_BUTTON_RIGHT && p_action == GLFW_PRESS)
        std::cout << "right mouse button pressed\n";
}

void
OGL::scroll_callback(GLFWwindow * p_window, double p_xoffset, double p_yoffset) {

    std::cout << "scroll: " << p_xoffset << ", " << p_yoffset << std::endl;
}

void
OGL::key_callback(GLFWwindow * p_window, int p_key, int p_scancode, int p_action, int p_mods) {
    
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
