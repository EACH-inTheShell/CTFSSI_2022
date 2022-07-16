cmake_minimum_required(VERSION 3.18)
project(umladinonosfios)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(map src/map.cpp)
add_library(net src/net.cpp)

add_executable(server src/server.cpp)
target_link_libraries(server map net pthread)

add_executable(client src/client.cpp)
target_link_libraries(client map net)
