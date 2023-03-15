#include "src/ogl.h"
#include "glprojects/triangle2d/triangle2d.hpp"
#include "glprojects/quad3d/quad3d.hpp"
#include "glprojects/dummy/dummy.hpp"
#include "glprojects/coordinateSystem/coordinatesystem.hpp"

int
main() {

    std::cout << "Hello OGL!" << std::endl;
    
	Triangle2D
	* triangle2D = new Triangle2D( "Triangle2D" );
/*
	Dummy
	* dummy = new Dummy ( );

	Quad3D
	* quad3D = new Quad3D( "Quad3D" );

	CoordinateSystem
	* coordinateSystem = new CoordinateSystem( "CoordinateSystem" );
*/

    OGL
    ogl;

    ogl.exec();

    std::cout << "God Bye OGL!" << std::endl;

    return 0;
}