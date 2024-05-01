find_package(benchmark CONFIG REQUIRED)

add_executable(mandel-bench main.cpp)
target_link_libraries(mandel-bench PUBLIC lib benchmark::benchmark_main)
target_folder(mandel-bench "Tools")
