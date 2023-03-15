#ifndef TRIANGLE2D_HPP
#define TRIANGLE2D_HPP

#include "../../src/glr.hpp"

using namespace glr;

class Triangle2D :
public GLProject {

	public:

		Triangle2D(CStr const & p_name = "Triangle2D");

	public:

		void
		init();

		void
		paint();

		void
		resize(int p_width, int p_height);

};
#endif // SIMPLETRIANGLE_HPP
