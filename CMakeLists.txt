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

set(SOURCES
    core/systems/render_system.cpp
    core/systems/collision_system.cpp
    render/renderer.cpp
    core/simulator.cpp
    main.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/core ${CMAKE_SOURCE_DIR}/render)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glog::glog)
