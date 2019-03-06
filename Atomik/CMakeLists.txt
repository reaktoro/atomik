# Collect all header, source, and test files from the current directory
file(GLOB_RECURSE HPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
file(GLOB_RECURSE CXX_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.test.cxx)

# Compile the source files into a library
add_library(Atomik SHARED ${HPP_FILES} ${CPP_FILES})

# Set the include directories of the library
target_include_directories(Atomik PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>           # include path needed during building
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)  # include path needed for codes using this library

# Set the libraries to be linked against
target_link_libraries(Atomik PUBLIC yaml-cpp)

# Set the compilation features to be propagated to client code.
target_compile_features(Atomik PUBLIC cxx_std_17)

# Create an install target for the header files
install(DIRECTORY ${CMAKE_SOURCE_DIR}/Atomik
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    FILES_MATCHING PATTERN "*.hpp")

# Create an install target for the library
install(TARGETS Atomik
    EXPORT AtomikTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries)

# Build the testing application
add_executable(tests ${CXX_FILES})
target_include_directories(tests PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(tests Atomik)
