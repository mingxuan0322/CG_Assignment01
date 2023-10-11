# cmake_minimum_required(VERSION 3.1)
cmake_minimum_required(VERSION 3.1...3.27.7)


project(point_in_polygon)

# Project sources
add_executable(${PROJECT_NAME} main.cpp)

# Use C++11 version of the standard
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

# Place the output binary at the root of the build folder
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
