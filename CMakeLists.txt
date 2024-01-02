cmake_minimum_required(VERSION 3.20)

# Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project
project(libcfgpathTests)
add_executable(libcfgpathTests)
target_include_directories(libcfgpathTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(libcfgpathTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test-macos-c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test-macos-cpp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

# libcfgpath
target_include_directories(libcfgpathTests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../libcfgpath/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(libcfgpathTests PRIVATE libcfgpath)

# Compile options
target_compile_options(libcfgpathTests
        PUBLIC
        -Wall
        -Wpedantic
        -Wextra
        -Werror
)
