cmake_minimum_required(VERSION 3.22)
project(ecs)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#------------------------------------------
# Prevent in-source builds.
#------------------------------------------
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message( FATAL_ERROR "In-source build is not recommended. Choose an empty directory for build output." )
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})


set(WITH_GFLAGS ON)
set(WITH_GTEST OFF)
set(WITH_UNWIND OFF)
    
add_subdirectory(third_party/glog)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} glog::glog)
