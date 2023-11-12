#include <chrono>

struct SimTime {
    std::chrono::milliseconds time;
    std::chrono::milliseconds dt;
};
