cmake_minimum_required(VERSION 3.22)
project(shojin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#------------------------------------------
# Prevent in-source builds.
#------------------------------------------
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message( FATAL_ERROR "In-source build is not recommended. Choose an empty directory for build output." )
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build.")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release)

set(WITH_GFLAGS ON)
set(WITH_GTEST OFF)
set(WITH_UNWIND OFF)

add_subdirectory(third_party/glog)
add_subdirectory(third_party/glad)
add_subdirectory(third_party/glm)
add_subdirectory(third_party/flatbuffers)

set(BUILD_SHARED_LIBS ON)
add_subdirectory(third_party/glfw)

set(SOURCES
    core/systems/init_system.cpp
    core/systems/render_system.cpp
    core/systems/collision_system.cpp
    render/renderer.cpp
    core/simulator.cpp
    main.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/third_party/glad ${CMAKE_SOURCE_DIR}/core ${CMAKE_SOURCE_DIR}/render ${CMAKE_SOURCE_DIR}/third_party/flatbuffers)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glog::glog glfw glad glm flatbuffers)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

OPTION(BUILD_UNIT_TESTS "Build Unit Tests"  ON)

IF (BUILD_UNIT_TESTS)
    ENABLE_TESTING()
    SUBDIRS(${CMAKE_CURRENT_LIST_DIR}/third_party/googletest)
    include_directories(${CMAKE_CURRENT_LIST_DIR}/third_party/googletest/include)
    SUBDIRS(test)
ENDIF()
