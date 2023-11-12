#pragma once

#include <memory>
#include <vector>

#include "systems/system.hpp"
#include "sim_time.hpp"
/**
 * This class manages all the systems and the visulaization of this collision simulator
 */
class Simulator final {
  public:
    Simulator();
    void step();

  private:
    SimTime time_;
    std::vector<std::unique_ptr<System>> systems_;
};
