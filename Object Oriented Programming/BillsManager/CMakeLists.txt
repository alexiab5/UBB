cmake_minimum_required(VERSION 3.27)
project(testqt1)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(testqt1 main.cpp
        billsgui.cpp
        billsgui.h
        billsgui.ui
        domain.h
        domain.cpp
        domain.cpp
        domain.h
        repository.h
        repository.h
        repository.cpp
        service.h
        service.cpp
        billsgui.h
        billsListModel.h
        billsListModel.cpp
        billsListFilterProxyModel.h
        billsListFilterProxyModel.cpp)

target_link_libraries(testqt1
        Qt::Core
        Qt6::Widgets
)