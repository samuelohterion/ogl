#ifndef GLWINDOW_CPP
#define GLWINDOW_CPP

#include "glwindow.h"
#include <math.h>
#include "verbose.cpp"
/*
GLWindow::GLWindow() {

    initGL();
}
*/

GLWindow::GLWindow(GLuint const & p_width, GLuint const & p_height, GLchar const * const & p_title) {

    verbose("GLWindow::GLWindow(GLuint const & p_width, GLuint const & p_height, GLchar const * const & p_title)")

    initGL(p_width, p_height, p_title);
}

GLWindow::~GLWindow() {

    verbose("GLWindow::~GLWindow()")

    cleanup();
}

void
GLWindow::addGLProject(GLProject * p_glProject) {

    verbose("void GLWindow::addGLProject(GLProject * p_glProject)")
	verbose("\tadd GLProject" << p_glProject -> name());

    p_glProject -> init();

	projects[p_glProject -> name()] = p_glProject;
}

void
GLWindow::exec() {

    verbose("void GLWindow::exec()")

    while (! glfwWindowShouldClose(__window)) {

        glfwPollEvents();

        paintGL();

        glfwSwapBuffers(__window);
    }
}

void
GLWindow::cleanup() {

    verbose("void GLWindow::cleanup()")

    for(auto & p : projects) {

        verbose("\tdelete " << p.second -> name())

        delete p.second;
    }

    glfwTerminate();

    glfwDestroyWindow(__window);

    GLWMan::getInstance() -> deleteWindow(__window);
}

void
GLWindow::cursor_position(double p_xpos, double p_ypos) {

    verbose("void GLWindow::cursor_position(double p_xpos, double p_ypos)")

    std::cout << "mouse pos: " << p_xpos << ", " << p_ypos << std::endl;

    GLint
    width,
    height;
    
    glfwGetWindowSize(__window, & width, & height);

    viewControlData.dMouse = glm::vec2(
		p_xpos - viewControlData.mousex,
		height - 1 - p_ypos - viewControlData.mousey);

	viewControlData.mousex = p_xpos;
	viewControlData.mousey = height - 1 - p_ypos;
}

void
GLWindow::fb_resize(int p_width, int p_height) {
    
    verbose("void GLWindow::fb_resize(int p_width, int p_height)")

    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, p_width, p_height);
}

int
GLWindow::initGL(GLuint const & p_width, GLuint const & p_height, GLchar const * const & p_title) {

    verbose("int GLWindow::initGL(GLuint const & p_width, GLuint const & p_height, GLchar const * const & p_title)")

    if (! glfwInit()) {

        std::cout << "glfwInit() failed! Exit with error code EXIT_FAILURE." << std::endl;

        return EXIT_FAILURE;
    }

    __window = glfwCreateWindow(p_width, p_height, p_title, NULL, NULL);

    GLWMan::getInstance() -> addWindow(this);

    glfwMakeContextCurrent(__window);

    if (! gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {

        std::cout << "Loading GL via glad failed! Exit with error code EXIT_FAILURE." << std::endl;

        glfwTerminate();

        return EXIT_FAILURE;
    }

    glClearColor(.25f, .5f, .75f, 1.f);

	viewControlData.width  = p_width;
	viewControlData.height = p_height;

	viewControlData.mousex = viewControlData.width >> 1;
	viewControlData.mousey = viewControlData.height >> 1;
	viewControlData.ticks = 0;

	viewControlData.dMouse = glm::vec2(0, 0);

	viewControlData.buttons = 0;
	viewControlData.time    = 0;

	viewControlData.ok = true;

	glViewport(0, 0, viewControlData.width, viewControlData.height);

	if(0 < projects.count(currentProject)) {

		projects[currentProject] -> setViewControlData(& viewControlData);
		projects[currentProject] -> init();
	}

    return EXIT_SUCCESS;
}

void
GLWindow::key(int p_key, int p_scancode, int p_action, int p_mods) {
    
    verbose("void GLWindow::key(int p_key, int p_scancode, int p_action, int p_mods)")

    if (p_key == GLFW_KEY_ESCAPE && p_action == GLFW_PRESS) {
        
        glfwSetWindowShouldClose(__window, GLFW_TRUE);
    }
}

void
GLWindow::mouse_button(int p_button, int p_action, int p_mods) {

    verbose("void GLWindow::mouse_button(int p_button, int p_action, int p_mods)")

    if (p_button == GLFW_MOUSE_BUTTON_LEFT && p_action == GLFW_PRESS)
        std::cout << "left mouse button pressed\n";

    if (p_button == GLFW_MOUSE_BUTTON_MIDDLE && p_action == GLFW_PRESS)
        std::cout << "middle mouse button pressed\n";

    if (p_button == GLFW_MOUSE_BUTTON_RIGHT && p_action == GLFW_PRESS)
        std::cout << "right mouse button pressed\n";
}

void
GLWindow::paintGL() {
    
    verbose("GLWindow::paintGL()")

    GLdouble
    time = glfwGetTime();

    glClearColor(.25f, .5f, .5 + .5 * sin(time), 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

	if(0 < projects.count(currentProject)) {

        verbose("\tpaint current project: " << currentProject)
		projects[currentProject] -> paint();
	}

	viewControlData.dMouse = glm::vec2(0.f, 0.f);

	viewControlData.ticks = 0;
}

void
GLWindow::removeGLProject(CStr  & p_name) {

    verbose("void GLWindow::removeGLProject(CStr  & p_name)")
    
    verbose("\tdelete projects[" << p_name << "]")
    delete projects[p_name];

    verbose("\terase entry from projects")
	projects.erase(p_name);
}

void
GLWindow::selectGLProject(CStr & p_projectName) {

    verbose("void GLWindow::selectGLProject(CStr & p_projectName)")

    if (0 < projects.count(p_projectName)) {

        verbose("\tcurrentProject = " << p_projectName)
        currentProject = p_projectName;
    }
}

void
GLWindow::scroll_wheel(double p_xoffset, double p_yoffset) {

    verbose("void GLWindow::scroll_wheel(double p_xoffset, double p_yoffset)")

    std::cout << "scroll: " << p_xoffset << ", " << p_yoffset << std::endl;
}

void
GLWindow::win_resize(int p_width, int p_height) {
    
    verbose("void GLWindow::win_resize(int p_width, int p_height)")

    viewControlData.width  = p_width;
	viewControlData.height = p_height;

	viewControlData.aspect = glm::vec2(p_width, p_height) / float(p_width < p_height ? p_height : p_width);

	viewControlData.mousex = viewControlData.width >> 1;
	viewControlData.mousey = viewControlData.height >> 1;

	if(0 < projects.count(currentProject)) {

		projects[currentProject] -> resizeViewport(p_width, p_height);
		projects[currentProject] -> resize(p_width, p_height);
	}
}
#endif