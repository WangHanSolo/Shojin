#include "collision_system.hpp"

#include "fbs/cubes_generated.h"

void CollisionSystem::initialize() {
    LOG(INFO) << "Collision System Initialized";
}
void CollisionSystem::update() {
    auto cubes = GetMutableCubes(fb_buffer_.ptr);
    auto positions = cubes->mutable_positions();

    for (auto pos : *positions){
        pos->mutate_x(pos->x() + 0.01);
        pos->mutate_y(pos->y() + 0.01);
        pos->mutate_z(pos->z() + 0.01);
    }

    LOG(INFO) << "Collision System Update";
}
