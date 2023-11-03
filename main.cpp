#include <glog/logging.h>
#include "simulator.hpp"


#include <iostream>

// settings


int main(int argc, char* argv[])
{

    LOG(INFO) << "Hello World";

    //  if no glog related flags passed, we assume INFO level logging
    if (argc < 2) {
        FLAGS_stderrthreshold = 0;
        google::InitGoogleLogging(argv[0]);
    } else {
        google::InitGoogleLogging(argv[0]);
        gflags::ParseCommandLineFlags(&argc, &argv, true);
    }

    float time = 0;

    auto game = Simulator();
    while (time < 100) {
        game.step();
        time += 1;
    }

    // uncomment this call to draw in wireframe polygons.
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
//    do{
//    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwGetKey(window, GLFW_KEY_Q) != GLFW_PRESS&& glfwWindowShouldClose(window) == 0);

    return 0;
}
