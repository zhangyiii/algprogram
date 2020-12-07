# cmake_minimum_required(VERSION <specify CMake version here>)
project(clion_proj)

set(CMAKE_CXX_STANDARD 11)
add_executable(clion_proj main.cpp gtestcase.cpp)

target_link_libraries(clion_proj -lgtestd -lgtest_maind -lpthread)