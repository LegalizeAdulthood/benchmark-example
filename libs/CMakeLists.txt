add_library(mandel
    include/mandel/mandel.h
    include/mandel/ComplexT.h
    mandel.cpp
)
target_include_directories(mandel PUBLIC include)
target_folder(mandel "Libraries")
