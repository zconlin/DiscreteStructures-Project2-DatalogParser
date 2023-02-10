cmake_minimum_required(VERSION 3.23)
project(CS236Project2-DatalogParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS236Project2-DatalogParser main.cpp datalogProgram.h rule.h predicate.h Parameter.h)
