cmake_minimum_required(VERSION 3.16)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Add source file of project root directory as source file.
set(srcFiles NumberOfIslands.cpp)

# Add executable target with source files.
add_executable(numberOfIslands ${srcFiles})
target_include_directories(numberOfIslands PUBLIC ../..)
