cmake_minimum_required(VERSION 3.0)

project(app)

find_package(Atomik)

add_executable(app main.cpp)

target_link_libraries(app Atomik::Atomik)
