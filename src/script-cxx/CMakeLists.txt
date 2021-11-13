# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Use C++11
set (CMAKE_CXX_STANDARD 11)

if( PROBLEM_NUMBER )
  message("PROBLEM_NUMBER=${PROBLEM_NUMBER}")
endif()

# Set the project name
project (leetcode)

message("projsrc=${PROJECT_SOURCE_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/gtest")
add_subdirectory("${PROJECT_SOURCE_DIR}/gtest")

# Add an executable
# file(GLOB SOURCE_FILES "*.cpp")

string(CONCAT CPP_NAME "${PROBLEM_NUMBER}" "-*.cpp")
message("CPP-NAME is ${CPP_NAME}")

if (${PROBLEM_NUMBER})
  file(GLOB SOURCE_FILES "${CPP_NAME}")
  add_executable(leetcode ${SOURCE_FILES})
  # Link with gtest
  target_link_libraries(leetcode gtest gtest_main)

  add_custom_target(run
    COMMAND ./leetcode
    )
endif()
