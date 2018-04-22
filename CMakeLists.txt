project(GlobalSign)
cmake_minimum_required(VERSION 2.8)

include(../conanbuildinfo.cmake)
conan_basic_setup()

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
