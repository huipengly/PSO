cmake_minimum_required(VERSION 3.5)
project(pso)

set(CMAKE_CXX_STANDARD 11)

add_executable(pso main.cpp pso.cpp pso.h Rosenbrock.cpp Rosenbrock.h)