#include <glog/logging.h>

int main(int argc, char* argv[]) {

    // if no glog related flags passed, we assume INFO level logging
    if (argc < 2){
        FLAGS_stderrthreshold = 0;
        google::InitGoogleLogging(argv[0]);
    } else{
        google::InitGoogleLogging(argv[0]);
        gflags::ParseCommandLineFlags(&argc, &argv, true);
    }


    LOG(INFO) << "Hello World";
}
