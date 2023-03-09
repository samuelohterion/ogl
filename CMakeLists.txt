cmake_minimum_required(VERSION 3.0.0)

project(ogl VERSION 0.1.0)

add_executable(ogl
    src/main.cpp
    glad/include/glad/glad.h
    glad/src/glad.c
)
add_library(glad STATIC glad/src/glad.c)
target_link_libraries(ogl dl glfw glad)

