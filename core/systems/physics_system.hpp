#pragma once

#include "system.hpp"

class PhysicsSystem final : public System {
    public:
        PhysicsSystem();
        ~PhysicsSystem();
        void update();
        void initialize();
};
