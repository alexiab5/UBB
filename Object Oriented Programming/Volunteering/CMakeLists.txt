cmake_minimum_required(VERSION 3.27)
project(test2)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(test2 main.cpp
        department.h
        volunteer.h
        repository.h
        repository.cpp
        observer.h
        controller.h
        controller.cpp
        window.cpp
        depwindow.h
        depwindow.cpp
)

target_link_libraries(test2
        Qt::Core
        Qt6::Widgets
)