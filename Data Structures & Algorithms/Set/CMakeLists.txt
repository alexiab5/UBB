cmake_minimum_required(VERSION 3.27)
project(Set__1_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Set__1_
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h)
