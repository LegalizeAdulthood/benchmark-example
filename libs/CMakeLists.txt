add_library(lib
    include/lib/lib.h
    include/lib/ComplexT.h
    lib.cpp
)
target_include_directories(lib PUBLIC include)
target_folder(lib "Libraries")
