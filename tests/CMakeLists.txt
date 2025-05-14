include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_executable(test-lib ComplexT_test.cpp)
target_link_libraries(test-lib PUBLIC lib GTest::gtest_main)
target_folder(test-lib "Tests")

gtest_discover_tests(test-lib)
