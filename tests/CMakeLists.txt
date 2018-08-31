include_directories(${PROJECT_SOURCE_DIR})
add_library(AtomikCatch OBJECT catch.hpp catch.cpp)
add_executable(AtomikTests tests.cpp $<TARGET_OBJECTS:catch>)
target_link_libraries(AtomikTests AtomikShared)
