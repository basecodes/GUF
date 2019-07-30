cmake_minimum_required(VERSION 3.1...3.15)
project(GUF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ")

add_subdirectory(GUF)

LIST(APPEND SOURCES
        main.cpp
        AppDelegate.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} GUFLIB)