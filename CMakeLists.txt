cmake_minimum_required(VERSION 3.20)
project(Timer_Qt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Timer_Qt main.cpp)
target_link_libraries(Timer_Qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

