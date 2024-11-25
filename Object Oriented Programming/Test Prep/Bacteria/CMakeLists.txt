cmake_minimum_required(VERSION 3.27)
project(test4)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(test4 main.cpp
        biologist.h
        repository.h
        bacteria.h
        tablemodel.h
        repository.cpp
        tablemodel.cpp
        gui.h
        gui.h
        gui.cpp
)

target_link_libraries(test4
        Qt::Core
        Qt6::Widgets
)