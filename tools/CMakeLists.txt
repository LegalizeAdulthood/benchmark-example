find_package(benchmark CONFIG REQUIRED)

add_executable(mandel-bench
    iterate.cpp
    main.cpp)
target_link_libraries(mandel-bench PUBLIC mandel benchmark::benchmark_main)
target_folder(mandel-bench "Tools")
