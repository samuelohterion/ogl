#include "glad/include/glad/glad.h"
#include "src/glwman.h"
#include "src/glwindow.h"
#include "glprojects/triangle2d/triangle2d.hpp"
#include "glprojects/quad3d/quad3d.hpp"
#include "glprojects/dummy/dummy.hpp"
#include "glprojects/coordinateSystem/coordinatesystem.hpp"

#include "src/verbose.cpp"

int
main() {

	verbose("Hello GLWindow!")

    GLWindow
    glwindow;

	Triangle2D *
	triangle2D = new Triangle2D("Triangle2D");
/*
	GLWindow
    glwindow2;

	Dummy *
	dummy = new Dummy("Dummy"); 
*/
	glwindow.addGLProject(triangle2D);

//	glwindow2.addGLProject(dummy);

	glwindow.selectGLProject(triangle2D -> name());

//    glwindow2.selectGLProject(dummy -> name());

    glwindow.exec();

//    glwindow2.exec();
 	
	verbose("God Bye GLWindow!")

    return EXIT_SUCCESS;
}