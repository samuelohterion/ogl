#include "glad/include/glad/glad.h"
#include "src/glwman.h"
#include "src/glwindow.h"
#include "glprojects/triangle2d/triangle2d.hpp"
#include "glprojects/quad3d/quad3d.hpp"
#include "glprojects/dummy/dummy.hpp"
#include "glprojects/coordinateSystem/coordinatesystem.hpp"

#include "src/verbose.cpp"
#include <iostream>
#include <map>

#define NUMER_OF_WINDOWS 5

int
main() {

	verbose("Hello GLWindow!")

	std::map< std::string, GLWindow * >
	windows;

	for(int i = 0; i < NUMER_OF_WINDOWS; ++ i) {

		std::stringstream
		ssname;
		
		ssname << "GLWin " << i;

		std::string
		name = ssname.str();
		
		windows[name] = new GLWindow(320, 200, name.c_str());
	}

	for(auto & w : windows) {

		Triangle2D *
		triangle2D = new Triangle2D("Triangle2D");

		w.second->addGLProject(triangle2D);
		w.second->selectGLProject(triangle2D -> name());
		w.second->exec(); //hier kommen wir nicht mehr raus. das muss ein thread werden.
	}

	//windows["GLWin 1"]->exec();

	verbose("God Bye GLWindow!")

    return EXIT_SUCCESS;
}