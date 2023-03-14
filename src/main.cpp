#include <iostream>
#include <math.h>
#include "../glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

GLuint const 
WIDTH  = 300,
HEIGHT = 200;

GLchar const *
TITLE = "OGL";

class OGL {

    private:

        GLFWwindow
        * __window;


    public:

        OGL() {

            initGL();
        }

        ~OGL() {

            cleanup();
        }

        int
        initGL() {

            if (! glfwInit()) {

                std::cout << "glfwInit() failed! Exit with error code -1." << std::endl;

                return -1;
            }

            __window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

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
        exec() {

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
        cleanup() {

            glfwTerminate();

            glfwDestroyWindow(__window);
        }
        
        static void
        key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
            
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
                
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
        }
        
        static void
        framebufferSizeCallback(GLFWwindow* window, int w, int h) {
            
            // make sure the viewport matches the new window dimensions; note that width and 
            // height will be significantly larger than specified on retina displays.
            glViewport(0, 0, w, h);
       }
};

int
main() {

    std::cout << "Hello OGL!" << std::endl;

/*
    OGL
    * ogl = new OGL();

    ogl->exec();
 */
    // This way seems also to work fine
    OGL
    ogl;

    ogl.exec();
    // This way seems also to work fine

    std::cout << "God Bye OGL!" << std::endl;

    return 0;
}