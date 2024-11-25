cmake_minimum_required(VERSION 3.27)
project(test3)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(test3 main.cpp
        pacient.h
        doctor.h
        repository.h
        controller.h
        controller.cpp
        observer.h
        window.h
        window.cpp
        statisticswindow.h
        statisticswindow.h
        statisticswindow.cpp
)

target_link_libraries(test3
        Qt::Core
        Qt6::Widgets
)