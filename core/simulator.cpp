#include "simulator.hpp"
#include "systems/init_system.hpp"
#include "systems/collision_system.hpp"
#include "systems/render_system.hpp"

Simulator::Simulator() {

    std::unique_ptr<System> init_system_ptr = std::make_unique<InitSystem>();
    std::unique_ptr<System> render_system_ptr = std::make_unique<RenderSystem>();
    std::unique_ptr<System> collision_system_ptr = std::make_unique<CollisionSystem>();

    init_system_ptr->initialize();
    render_system_ptr->initialize();
    collision_system_ptr->initialize();

    systems_.push_back(std::move(init_system_ptr));
    systems_.push_back(std::move(render_system_ptr));
    systems_.push_back(std::move(collision_system_ptr));
}

void Simulator::step() {
    for (auto& system : systems_) {
        system->update();
    }
}
