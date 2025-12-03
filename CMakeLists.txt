cmake_minimum_required(VERSION 3.20)

project(InOneWeekend LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Gather all source files under src/InOneWeekend
file(GLOB_RECURSE SOURCES
    src/InOneWeekend/*.cpp
)

add_executable(inOneWeekend ${SOURCES})

# Include directories
target_include_directories(inOneWeekend PRIVATE
    src/InOneWeekend
)
