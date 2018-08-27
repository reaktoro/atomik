# Set cmake version requirement
cmake_minimum_required(VERSION 3.1)

# Set the name of the project
project(Atomik VERSION 0.1 LANGUAGES CXX)

# Set the cmake module path of the project
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Include the cmake variables with values for installation directories
include(GNUInstallDirs)

# Set the output directories of the built libraries and binaries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# Define which types of libraries to build
option(BUILD_SHARED_LIBS "Build shared libraries." ON)
option(BUILD_STATIC_LIBS "Build static libraries." ON)

# Atomik currently is not setup to produce a dynamic library using MSVC, only static
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(BUILD_SHARED_LIBS OFF)
endif()

# Build the C++ library Atomik
add_subdirectory(Atomik)

# Build the C++ Atomik tests
add_subdirectory(tests)
