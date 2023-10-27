cmake_minimum_required(VERSION 3.22)
project(glad)

add_library(glad ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/gl.h ${CMAKE_CURRENT_SOURCE_DIR}/src/gl.c)
target_include_directories(glad PUBLIC include/)

