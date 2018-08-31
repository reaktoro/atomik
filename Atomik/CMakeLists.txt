# Collect all header files from the current directory for the C++ library
file(GLOB_RECURSE HPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)

# Collect all source files from the current directory for the C++ library
file(GLOB_RECURSE CPP_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# The name of the shared and static libraries
set(PROJECT_SHARED_LIB ${PROJECT_NAME}${SUFFIX_SHARED_LIBS})
set(PROJECT_STATIC_LIB ${PROJECT_NAME}${SUFFIX_STATIC_LIBS})

# Compile Atomik cpp files into object files
add_library(AtomikObject OBJECT ${HPP_FILES} ${CPP_FILES})

# Add the root path of this project to the cmake include directories
target_include_directories(AtomikObject PUBLIC ${PROJECT_SOURCE_DIR})

# Set some properties for the AtomikObject target
set_property(TARGET AtomikObject PROPERTY POSITION_INDEPENDENT_CODE ON)

# Ensure Atomik is compiled with a compiler that supports C++11
set_property(TARGET AtomikObject PROPERTY CXX_STANDARD 11)

# Check if a shared library for Atomik must be built
if(BUILD_SHARED_LIBS)
    add_library(AtomikShared SHARED $<TARGET_OBJECTS:AtomikObject>)
    set_target_properties(AtomikShared PROPERTIES OUTPUT_NAME Atomik)
    install(TARGETS AtomikShared DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries)
endif()

# Check if a static library for Atomik must be built
if(BUILD_STATIC_LIBS)
    add_library(AtomikStatic STATIC $<TARGET_OBJECTS:AtomikObject>)
    set_target_properties(AtomikStatic PROPERTIES OUTPUT_NAME Atomik)
    install(TARGETS AtomikStatic DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries)
endif()

# Create an install target for Atomik header files
install(DIRECTORY ${CMAKE_SOURCE_DIR}/Atomik
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    FILES_MATCHING PATTERN "*.hpp")