cmake_minimum_required(VERSION 3.18)
project(umladinonosfios)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(server src/server.cpp)
target_link_libraries(server pthread)
