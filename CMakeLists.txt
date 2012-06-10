cmake_minimum_required(VERSION 2.6)
project(cmpstr CXX)

set(CMAKE_CXX_FLAGS "-g -Wall")

set(cmpstr_SOURCES cmpstr.cc)

add_executable(cmpstr ${cmpstr_SOURCES})
