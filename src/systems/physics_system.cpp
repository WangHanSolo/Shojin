#include "physics_system.hpp"
#include "glog/logging.h"

#include "fbs/cubes_generated.h"


PhysicsSystem::PhysicsSystem(){

}

PhysicsSystem::~PhysicsSystem(){

}

void PhysicsSystem::initialize(){
    LOG(INFO) << "Physics System Initialize";
}

void PhysicsSystem::update(){
    LOG(INFO) << "Physics System Update";

    auto cubes_fb_vector_ptr = GetMutableCubes(fb_buffer_.ptr);
    auto cubes_vector_ptr = cubes_fb_vector_ptr->mutable_cubes();
    auto& cubes_vector = *cubes_vector_ptr;

    // update velocities




    for (auto cube : cubes_vector){
        auto accel = cube->mutable_accel();
        // update acceleration
        // TODO

        // update velocities
        auto vel = cube->mutable_vel();
        vel->mutate_x(vel->x() + accel->x());
        vel->mutate_y(vel->y() + accel->z());
        vel->mutate_z(vel->z() + accel->z());
        // update position
        auto pos = cube->mutable_pos();
        pos->mutate_x(pos->x() + vel->x());
        pos->mutate_y(pos->y() + vel->y());
        pos->mutate_z(pos->z() + vel->z());
    }



//    for (auto cube : *cubes->mutable_cubes()){
//        auto pos = *cube->mutable_pos();
//
//        LOG(INFO) << "hello: " <<pos.x();
//    }

}
