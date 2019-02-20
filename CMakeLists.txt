# Set cmake version requirement
cmake_minimum_required(VERSION 3.1)

# Set the name of the project
project(Atomik VERSION 0.1 LANGUAGES CXX)

# Set the cmake module path of the project
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Include the cmake variables with values for installation directories
include(GNUInstallDirs)

# Build the dependencies of the project
add_subdirectory(deps)

# Build the C++ library Atomik
add_subdirectory(Atomik)

# Build the C++ Atomik tests
add_subdirectory(tests)
