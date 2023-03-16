#include "glad/include/glad/glad.h"
#include "src/glwman.h"
#include "src/glwindow.h"
#include "glprojects/triangle2d/triangle2d.hpp"
#include "glprojects/quad3d/quad3d.hpp"
#include "glprojects/dummy/dummy.hpp"
#include "glprojects/coordinateSystem/coordinatesystem.hpp"

#define VERBOSE

int
main() {

	#ifdef VERBOSE
    	std::cout << "Hello GLWindow!" << std::endl;
	#endif

	Triangle2D
	* triangle2D = new Triangle2D("Triangle2D");

    GLWindow
    glwindow;

	glwindow.addGLProject(triangle2D);

	glwindow.selectGLProject(triangle2D -> name());

    glwindow.exec();

 	#ifdef VERBOSE
		std::cout << "God Bye GLWindow!" << std::endl;
	#endif

    return EXIT_SUCCESS;
}