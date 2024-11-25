cmake_minimum_required(VERSION 3.27)
project(testqt2)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(testqt2 main.cpp
        shoppingList.h
        shoppingList.cpp
        repository.h
        repository.cpp
        shoppinggui.cpp
        shoppinggui.h
        shoppinggui.ui
)

target_link_libraries(testqt2
        Qt::Core
        Qt6::Widgets
)