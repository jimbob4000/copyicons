
cmake_minimum_required(VERSION 3.10)
project(copyicons)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if(DEFINED ENV{VITASDK})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
    else()
        message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
    endif()
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")

add_library(copyicons STATIC
    copyicons.c
    ../../../../src/file.c
    ../../../../src/pfs.c
)

target_include_directories(copyicons PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ../../../../src
    ../../../../modules/user
    ../../../../modules/kernel
)
