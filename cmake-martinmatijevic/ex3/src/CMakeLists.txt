add_library(Sqrt STATIC sqrt.cpp ../include/sqrt.h)
add_executable(ex3prog main.cpp)
target_link_libraries(ex3prog Sqrt)
