#include <glog/logging.h>
#include "system1.cpp"
#include "system2.cpp"

int main(int argc, char* argv[]) {

    // if no glog related flags passed, we assume INFO level logging
    if (argc < 2){
        FLAGS_stderrthreshold = 0;
        google::InitGoogleLogging(argv[0]);
    } else{
        google::InitGoogleLogging(argv[0]);
        gflags::ParseCommandLineFlags(&argc, &argv, true);
    }
    float time = 0;

    FirstSystem s1;
    SecondSystem s2;



    while (time < 10){
        s1.update();
        s2.update();
        time += 1;
    }


    LOG(INFO) << "Hello World";
}
