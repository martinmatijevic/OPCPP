cmake_minimum_required(VERSION 3.1)

project(Git CXX)

add_executable("gitmain" main.cpp)

set_target_properties(gitmain
  PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )
