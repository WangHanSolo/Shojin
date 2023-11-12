add_executable(
    shojin_clock
    shojin_clock/shojin_clock.cpp
)

target_link_libraries(
    shojin_clock
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(shojin_clock)
