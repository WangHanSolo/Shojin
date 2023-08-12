#include <glog/logging.h>
#include "simulator.hpp"

int main(int argc, char* argv[]) {
    // if no glog related flags passed, we assume INFO level logging
    if (argc < 2) {
        FLAGS_stderrthreshold = 0;
        google::InitGoogleLogging(argv[0]);
    } else {
        google::InitGoogleLogging(argv[0]);
        gflags::ParseCommandLineFlags(&argc, &argv, true);
    }
    float time = 0;

    auto game = Simulator();

    while (time < 10) {
        game.step();
        time += 1;
    }

    LOG(INFO) << "Hello World";
}
