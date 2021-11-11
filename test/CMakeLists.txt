cmake_minimum_required(VERSION 3.5)

find_package(GTest REQUIRED)

add_subdirectory(./lib/googletest/)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp testDate.cpp testTime.cpp testClock.cpp)
add_executable(timerQtTests ${TEST_SOURCE_FILES})
target_link_libraries(timerQtTests gtest gtest_main core)