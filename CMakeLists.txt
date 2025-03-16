cmake_minimum_required(VERSION 3.30)
project(ScreenShare)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_STATIC_LINKER_FLAGS "-static")

add_executable(ScreenShare main.cpp)
