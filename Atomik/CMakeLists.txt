# Collect all header files from the current directory for the C++ library
file(GLOB_RECURSE HPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)

# Collect all source files from the current directory for the C++ library
file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Collect all test source files from the current directory for the C++ testing suite
file(GLOB_RECURSE CXX_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.test.cxx)

# The name of the shared and static libraries
set(PROJECT_SHARED_LIB ${PROJECT_NAME}${SUFFIX_SHARED_LIBS})
set(PROJECT_STATIC_LIB ${PROJECT_NAME}${SUFFIX_STATIC_LIBS})

# Compile Atomik cpp files into object files
add_library(AtomikObject OBJECT ${HPP_FILES} ${CPP_FILES})

# Add the root path of this project to the cmake include directories
target_include_directories(AtomikObject PUBLIC ${PROJECT_SOURCE_DIR})

# Set some properties for the AtomikObject target
set_property(TARGET AtomikObject PROPERTY POSITION_INDEPENDENT_CODE ON)

# Ensure Atomik is compiled with a compiler that supports C++17
set_property(TARGET AtomikObject PROPERTY CXX_STANDARD 17)

# Check if a shared library for Atomik must be built
add_library(Atomik SHARED $<TARGET_OBJECTS:AtomikObject>)
install(TARGETS Atomik DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries)

# Create an install target for Atomik header files
install(DIRECTORY ${CMAKE_SOURCE_DIR}/Atomik
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    FILES_MATCHING PATTERN "*.hpp")

# Build the test application
add_executable(AtomikTests ${CXX_FILES})
set_target_properties(AtomikTests PROPERTIES CXX_STANDARD 17)
target_include_directories(AtomikTests PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(AtomikTests PUBLIC ${PROJECT_SOURCE_DIR}/deps)
target_link_libraries(AtomikTests Atomik)