#include "system.hpp"
#include <glog/logging.h>

class CollisionSystem final : public System {
  public:
    void update();
};
