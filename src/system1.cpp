#include "system.hpp"
#include <glog/logging.h>

class FirstSystem final : public System {
  public:
    void update() { LOG(INFO) << "First System"; }
};
