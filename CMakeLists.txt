# Set cmake version requirement
cmake_minimum_required(VERSION 3.1)

# Set the cmake module path of the project
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Use ccache to speed up repeated compilations
include(CCache)

# Set the name of the project
project(Atomik VERSION 0.1 LANGUAGES CXX)

# Include the cmake variables with values for installation directories
include(GNUInstallDirs)

# Ensure proper configuration if in a conda environment
include(CondaAware)

message(CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH})

# Find dependencies
find_package(Catch2 REQUIRED)

# Build the dependencies
add_subdirectory(deps)

# Build the C++ library Atomik
add_subdirectory(Atomik)
