# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Use C++11
set (CMAKE_CXX_STANDARD 11)

# Set the project name
project (leetcode)


include_directories("${PROJECT_SOURCE_DIR}/include")

# Add an executable
file(GLOB SOURCE_FILES "*.cpp")
add_executable(leetcode ${SOURCE_FILES})

