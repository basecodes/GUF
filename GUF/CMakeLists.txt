
project (GUFLIB)

file(GLOB SOURCES
        "src/*.cpp"
        "src/Windows/*.cpp"
        "src/Application/*.cpp"
        "src/InteractiveWidgets/*.cpp"
        "src/LayoutContainers/*.cpp"
        "src/Value/*.cpp"
        )
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/Windows
        ${PROJECT_SOURCE_DIR}/Application
        ${PROJECT_SOURCE_DIR}/InteractiveWidgets
        ${PROJECT_SOURCE_DIR}/LayoutContainers
        ${PROJECT_SOURCE_DIR}/Value
        )

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})