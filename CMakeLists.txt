cmake_minimum_required(VERSION 3.22)
project(ecs)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(third_party/glog)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} glog::glog)
