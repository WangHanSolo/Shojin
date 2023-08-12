#include "system.hpp"
#include <glog/logging.h>

class RenderSystem final : public System {
  public:
    void update();
};
