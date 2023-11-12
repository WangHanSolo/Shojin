#pragma once

#include <memory>
#include <vector>

#include "systems/system.hpp"
#include "shojin_time.hpp"
/**
 * This class manages all the systems and the visulaization of this collision simulator
 */
class Shojin final {
  public:
    Shojin(ShojinClock& clock);
    bool step();

  private:
    ShojinClock clock_;
    std::vector<std::unique_ptr<System>> systems_;
};
