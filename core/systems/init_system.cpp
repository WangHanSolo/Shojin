#include "init_system.hpp"
#include "glog/logging.h"

#include "fbs/cubes_generated.h"


InitSystem::InitSystem(){

}

InitSystem::~InitSystem(){

}

void InitSystem::initialize(){

    Vec3 pos = Vec3(0.0, 0.0f, 0.0f);
    Vec3 accel = Vec3(0.01, 0.01, 0.01);
    Vec3 vel = Vec3(0.05, 0.05, 0.05);
    float mass = 1;
    // create a cube
    auto cube = CreateCube(fbb_, &pos, &accel, &vel, mass);

    // create flatbuffer vector of cubes
    std::vector<flatbuffers::Offset<Cube>> cubes_vector{cube};
    auto cubes_fbb_vector = fbb_.CreateVector(cubes_vector);
    LOG(INFO) << "init with size: " << cubes_vector.size();

    // Create parent cubes fb object
    auto cubes = CreateCubes(fbb_, cubes_fbb_vector);
    fbb_.Finish(cubes);

    fb_buffer_.ptr = fbb_.GetBufferPointer();
    fb_buffer_.size = fbb_.GetSize(); 
}

void InitSystem::update(){
    LOG(INFO) << "Init System Update";
    
}
