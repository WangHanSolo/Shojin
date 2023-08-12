#include "system.h"
#include <glog/logging.h>

class FirstSystem : public System{
    public:
        void update(){
            LOG(INFO) << "First System";
        }
};
