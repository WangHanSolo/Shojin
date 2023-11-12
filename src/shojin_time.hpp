#include <chrono>

struct ShojinClock {
    ShojinClock(int duration, int dt) : duration(duration), dt(dt){}
    std::chrono::milliseconds duration;
    std::chrono::milliseconds time;
    std::chrono::milliseconds dt;

    bool update(){
        if (time + dt > duration) return false;
        time += dt;
        return true;
    }
};
