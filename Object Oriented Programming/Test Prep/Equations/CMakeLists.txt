cmake_minimum_required(VERSION 3.27)
project(testqt5)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(testqt5 main.cpp
        equation.h
        equation.cpp
        gui.cpp
        gui.h
        gui.ui
        repo.h
        repo.cpp
)

target_link_libraries(testqt5
        Qt::Core
        Qt6::Widgets
)