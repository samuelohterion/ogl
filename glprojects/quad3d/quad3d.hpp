#ifndef COLOREDTRIANGLE3D_HPP
#define COLOREDTRIANGLE3D_HPP
#include "../../src/glr.hpp"

class Quad3D :
public GLProject {

	public:

		Quad3D(CStr const & p_name = "Quad3D");

	public:

		glm::mat4
		m,//odel
		v,//iew
		p,//projection
		mvp;//model-view-projection

	public:

		void
		init();

		void
		paint();

		void
		resize(int p_width, int p_height);

};
#endif // COLOREDTRIANGLE3D_HPP
