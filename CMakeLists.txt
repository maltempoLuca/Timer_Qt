cmake_minimum_required(VERSION 3.20)
project(Timer_Qt)

add_subdirectory(test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(SOURCE_FILES Sources/claase_per_provare_googleTest.cpp Headers/claase_per_provare_googleTest.h Sources/Date.cpp
        Headers/Date.h Sources/Time.cpp Headers/Time.h)
add_executable(Timer_Qt Sources/main.cpp Sources/mainwindow.cpp Headers/mainwindow.h Formats/mainwindow.ui)

add_library(core ${SOURCE_FILES})

target_link_libraries(Timer_Qt
        core
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

