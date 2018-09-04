include_directories(${PROJECT_SOURCE_DIR})
add_library(AtomikCatch OBJECT catch.hpp catch.cpp)
add_executable(AtomikTests tests.cpp $<TARGET_OBJECTS:catch>)
target_link_libraries(AtomikTests AtomikShared)

set_target_properties(AtomikCatch PROPERTIES CXX_STANDARD 11)
set_target_properties(AtomikTests PROPERTIES CXX_STANDARD 11)
