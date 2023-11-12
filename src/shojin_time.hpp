#include <chrono>

struct ShojinClock {
    // TODO; should check if duration and dt are valid...
    ShojinClock(int duration, int dt) : duration(duration), dt(dt), time(0){}
    std::chrono::milliseconds duration;
    std::chrono::milliseconds time;
    std::chrono::milliseconds dt;

    bool update(){
        if (time + dt > duration) return false;
        time += dt;
        return true;
    }
};
