#include "glad/include/glad/glad.h"
#include "src/glwman.h"
#include "src/glwindow.h"
#include "glprojects/triangle2d/triangle2d.hpp"
#include "glprojects/quad3d/quad3d.hpp"
#include "glprojects/dummy/dummy.hpp"
#include "glprojects/coordinateSystem/coordinatesystem.hpp"

int
main() {

    std::cout << "Hello GLWindow!" << std::endl;
    
	Triangle2D
	* triangle2D = new Triangle2D("Triangle2D");
/*
	Dummy
	* dummy = new Dummy ();

	Quad3D
	* quad3D = new Quad3D("Quad3D");

	CoordinateSystem
	* coordinateSystem = new CoordinateSystem("CoordinateSystem");
*/

    GLWindow
    glwindow;

	glwindow.addGLProject(triangle2D);

	glwindow.selectGLProject(triangle2D->name());

    glwindow.exec();

    std::cout << "God Bye GLWindow!" << std::endl;

    return 0;
}