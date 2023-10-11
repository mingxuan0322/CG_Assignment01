# cmake_minimum_required(VERSION 3.1)
cmake_minimum_required(VERSION 3.1...3.27.7)
#it worth record this issue:

# CMake Deprecation Warning at src/inside/CMakeLists.txt:1 (cmake_minimum_required):Compatibility with CMake < 3.5 will be removed from a future version of
# CMake.

# Update the VERSION argument <min> value or use a ...<max> suffix to tell
# CMake that the project does not need compatibility with older versions.

#solution: https://discourse.cmake.org/t/how-to-fix-cmake-minimum-required-deprecation-warning/2487/2


project(convex_hull)

# Project sources
add_executable(${PROJECT_NAME} main.cpp)

# Use C++11 version of the standard
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

# Place the output binary at the root of the build folder
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
