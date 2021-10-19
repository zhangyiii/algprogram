cmake_minimum_required(VERSION 3.5)
project(algprogram)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(algprogram ${SRC} sortAlgTest.cpp arryLeetCode.cpp)

target_link_libraries(algprogram libgtestd.a)