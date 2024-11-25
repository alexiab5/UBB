cmake_minimum_required(VERSION 3.27)
project(testqt3)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(testqt3 main.cpp
        veggie.h
        veggie.cpp
        repository.h
        repository.cpp
        vegetablesGUI.cpp
        vegetablesGUI.h
        vegetablesGUI.ui
)

target_link_libraries(testqt3
        Qt::Core
        Qt6::Widgets
)