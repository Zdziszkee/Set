cmake_minimum_required(VERSION 3.28)
project(Set)

set(CMAKE_CXX_STANDARD 17)

add_executable(Set Set.cpp Set.hpp tokenize.hpp)
