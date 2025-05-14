include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

add_executable(test-mandel ComplexT_test.cpp)
target_link_libraries(test-mandel PUBLIC mandel GTest::gtest_main)
target_folder(test-mandel "Tests")

gtest_discover_tests(test-mandel)
