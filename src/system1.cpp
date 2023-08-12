#include "system.hpp"
#include <glog/logging.h>

class FirstSystem : public System {
  public:
    void update() { LOG(INFO) << "First System"; }
};
