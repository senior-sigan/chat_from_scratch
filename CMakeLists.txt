cmake_minimum_required(VERSION 3.15)
project(my_imgui)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 2.5.0 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} raylib)