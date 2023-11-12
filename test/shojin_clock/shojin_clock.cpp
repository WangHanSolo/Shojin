#include <gtest/gtest.h>
#include <iostream>
#include "shojin_time.hpp"

TEST(ShojinClock, StepCount) {
    int duration = 5;
    int dt = 1;
    ShojinClock clock(duration, dt);

    int step_count = 0;
    while (clock.update()){
        step_count++;
    }
    EXPECT_EQ(step_count, duration);
}
