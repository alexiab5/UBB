cmake_minimum_required(VERSION 3.27)
project(t2_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(t2_2 main.cpp
        client.h
        client.cpp
        dwelling.h
        dwelling.cpp
        realEstateAgency.h
        realEstateAgency.cpp
        ui.cpp
        ui.h)
