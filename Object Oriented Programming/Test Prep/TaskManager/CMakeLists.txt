cmake_minimum_required(VERSION 3.27)
project(testqt4)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(testqt4 main.cpp
        task.cpp
        task.h
        repository.cpp
        repository.h
        tasksgui.cpp
        tasksgui.h
        tasksgui.ui
)

target_link_libraries(testqt4
        Qt::Core
        Qt6::Widgets
)