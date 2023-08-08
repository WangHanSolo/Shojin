#include <glog/logging.h>

int main(int argc, char* argv[]) {
    // Initialize Google's logging library
    google::InitGoogleLogging(argv[0]);

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    LOG(INFO) << "Hello World";
}
