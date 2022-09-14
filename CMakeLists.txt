cmake_minimum_required(VERSION 3.23)
project(Test_task_Vadim)

set(CMAKE_CXX_STANDARD 20)
add_executable(Test_task_Vadim main.cpp distance_two_line_segments.h)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
target_link_libraries(Test_task_Vadim gtest)