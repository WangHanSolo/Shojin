#include "init_system.hpp"
#include "glog/logging.h"

#include "fbs/cubes_generated.h"


InitSystem::InitSystem(){

}

InitSystem::~InitSystem(){

}

void InitSystem::initialize(){
     Vec3 points[] = { Vec3(1.0f, 1.0f, 1.0f), Vec3(4.0f, 5.0f, 6.0f)  };
     auto path = fbb_.CreateVectorOfStructs(points, 2);
     auto cubes = CreateCubes(fbb_, path);
     fbb_.Finish(cubes);
     fb_buffer_.ptr = fbb_.GetBufferPointer();
     fb_buffer_.size = fbb_.GetSize(); 
}

void InitSystem::update(){
    LOG(INFO) << "Init System Update";
    
}
