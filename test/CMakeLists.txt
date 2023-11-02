add_executable(
    test_test
    test.cpp
)

target_link_libraries(
    test_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_test)
