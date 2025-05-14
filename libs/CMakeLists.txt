find_package(hwy CONFIG REQUIRED)

add_library(mandel
    include/mandel/iterate.h
    include/mandel/span.h
    include/mandel/ComplexT.h
    highway_dynamic.h highway_dynamic.cpp
    highway_static.h highway_static.cpp
    iterate.cpp
    span.cpp
)
source_group("Header Files/Private" FILES
    highway_dynamic.h
    highway_static.h
)
target_include_directories(mandel PUBLIC include)
# This is needed so that the highway foreach_target.h mechanism works on ubuntu.
target_include_directories(mandel PRIVATE .)
target_link_libraries(mandel PUBLIC hwy::hwy)
target_folder(mandel "Libraries")
