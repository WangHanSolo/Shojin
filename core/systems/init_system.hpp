#pragma once

#include "system.hpp"

class InitSystem final : public System {
    public:
        InitSystem();
        ~InitSystem();
        void update();
        void initialize();
};
