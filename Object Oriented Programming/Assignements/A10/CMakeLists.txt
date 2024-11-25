cmake_minimum_required(VERSION 3.27)
project(oop-a10-alexiab5)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "E:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(oop-a10-alexiab5 main.cpp
        domain.h
        domain.cpp
        exceptions.h
        exceptions.cpp
        repository.h
        repository.cpp
        service.h
        service.cpp
        shoppingBasket.h
        shoppingBasket.cpp
        tests.h
        tests.cpp
        ui.cpp
        ui.h
        trenchCoatValidator.h
        trenchCoatValidator.cpp
        exceptions.cpp
        appGUI.h
        appGUI.cpp
        adminGUI.h
        adminGUI.cpp
        userGUI.h
        userGUI.cpp
        appGUI.cpp
        undoRedoCommands.h
        undoRedoCommands.cpp
        trenchCoatsTableModel.h
        trenchCoatsTableModel.cpp
)
target_link_libraries(oop-a10-alexiab5
        Qt::Core
        Qt6::Widgets
)
