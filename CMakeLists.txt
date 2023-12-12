cmake_minimum_required(VERSION 3.10)

project(sergio)

set(SOURCES
    ./src/vector.c
)

add_library(${PROJECT_NAME} ${SOURCES})

# set C standard
set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 11
    C_EXTENSIONS OFF
)

# include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
