add_library(mandel
    include/mandel/iterate.h
    include/mandel/span.h
    include/mandel/ComplexT.h
    iterate.cpp
    span.cpp
)
target_include_directories(mandel PUBLIC include)
target_folder(mandel "Libraries")
