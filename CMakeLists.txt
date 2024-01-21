cmake_minimum_required(VERSION 3.20)

# Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project
project(storepaths-tests)
add_executable(storepaths-tests)
target_sources(storepaths-tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test-common-c.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test-common-cpp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

# storepaths
add_subdirectory(storepaths)
target_include_directories(storepaths-tests PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/storepaths/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(storepaths-tests PRIVATE storepaths)

# Compile options
if(UNIX)
    target_compile_options(storepaths-tests
            PUBLIC
            -Wall
            -Wpedantic
            -Wextra
            -Werror
    )
# Windows raises lots of unnecessary warnings if compiled with /Wall
# so default compilation
endif()