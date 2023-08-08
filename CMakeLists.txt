cmake_minimum_required(VERSION 3.22)
project(ecs)


# Disallows include export result. 
# cmake_policy(SET CMP0024 OLD)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#------------------------------------------
# Prevent in-source builds.
#------------------------------------------
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message( FATAL_ERROR "In-source build is not recommended. Choose an empty directory for build output." )
endif(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_BINARY_DIR}/third_party")

set(WITH_GFLAGS ON)
set(WITH_GTEST OFF)
set(WITH_UNWIND OFF)
    
# add_subdirectory(third_party/gflags)
# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}/third_party/gflags")
add_subdirectory(third_party/glog)

set(gflags_DIR ${CMAKE_CURRENT_BINARY_DIR}/third_party/gflags)


add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} glog::glog)
