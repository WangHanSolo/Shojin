#pragma once
#include "flatbuffers/flatbuffers.h"

struct buffer{
    buffer(){}
    buffer(uint8_t* ptr, int size) : ptr(ptr), size(size){}
    uint8_t* ptr;
    int size;
};

class System {
  public:
    virtual ~System() {}
    virtual void initialize() = 0;
    virtual void update()     = 0;
  protected:
    inline static flatbuffers::FlatBufferBuilder fbb_ = flatbuffers::FlatBufferBuilder(1024);
    inline static buffer fb_buffer_ = buffer();
};
