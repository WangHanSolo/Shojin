#include "system.hpp"
#include <glog/logging.h>

class SecondSystem final : public System {
  public:
    void update() { LOG(INFO) << "Second System"; }
};
