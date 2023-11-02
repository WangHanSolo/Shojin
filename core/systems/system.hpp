#pragma once

class System {
  public:
    virtual ~System() {}
    virtual void initialize() = 0;
    virtual void update()     = 0;
};
