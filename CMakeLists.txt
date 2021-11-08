cmake_minimum_required(VERSION 3.20)
project(Timer_Qt)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(test)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCE_FILES Sources/claase_per_provare_googleTest.cpp Headers/claase_per_provare_googleTest.h
        Sources/Date.cpp Headers/Date.h Sources/Clock.cpp Headers/Clock.h
        Sources/mainwindow.cpp Headers/mainwindow.h Sources/Time.cpp Headers/Time.h)

add_executable(Timer_Qt Sources/main.cpp)
add_library(core ${SOURCE_FILES})

target_link_libraries(core
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
target_link_libraries(Timer_Qt core)