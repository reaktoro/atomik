# Set cmake version requirement
cmake_minimum_required(VERSION 3.1)

# Set the cmake module path of the project
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Use ccache to speed up repeated compilations
include(CCache)

# Set the name of the project
project(Atomik VERSION 0.1 LANGUAGES CXX)

# The a brief description of the project
set(PROJECT_BRIEF "A C++ library implementing basic chemical concepts.")

# Include the cmake variables with values for installation directories
include(GNUInstallDirs)

# Ensure proper configuration if in a conda environment
include(CondaAware)

# Find all public and private dependencies
include(FindDeps/All)

# Build the C++ library Atomik
add_subdirectory(Atomik)

# Install the cmake config files that permit users to use find_package(Atomik)
include(PackageFinding/Enable)
