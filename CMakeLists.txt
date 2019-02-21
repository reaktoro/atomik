# Set cmake version requirement
cmake_minimum_required(VERSION 3.1)

# Set the cmake module path of the project
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Set the name of the project
project(Atomik VERSION 0.1 LANGUAGES CXX)

# Include the cmake variables with values for installation directories
include(GNUInstallDirs)

# Find dependencies
find_package(Catch2 REQUIRED)

# Build the dependencies
add_subdirectory(deps)

# Build the C++ library Atomik
add_subdirectory(Atomik)
