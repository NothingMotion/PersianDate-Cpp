cmake_minimum_required(VERSION 3.20)
project(PersianDate_Cpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(PersianDate_Cpp STATIC
        src/persian_date.cpp
        include/persian_date.hpp)

target_include_directories(PersianDate_Cpp PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    option(PERSIANDATE_BUILD_TESTS "Build tests" ON)
else()
    option(PERSIANDATE_BUILD_TESTS "Build tests" OFF)
endif()

if(PERSIANDATE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()