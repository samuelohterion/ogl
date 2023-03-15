cmake_minimum_required(VERSION 3.1.0)

set(CXX_STANDARD 20)

project(ogl VERSION 0.1.0)

find_package(OpenGL REQUIRED)

add_executable(ogl
    main.cpp
    src/ogl.cpp
    glprojects/triangle2d/triangle2d.cpp
    glad/include/glad/glad.h
    glad/src/glad.c
)
add_library(glad STATIC glad/src/glad.c)
target_link_libraries(ogl
	${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
	${GLFW_LIBRARY}
	${GLEW_LIBRARY}
)

target_link_libraries(ogl dl glfw glad)
