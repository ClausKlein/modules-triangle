cmake_minimum_required(VERSION 4.2...4.3)

project(library_c LANGUAGES CXX)

option(LIBRARY_C_MODULES "Build library_c with C++20 module support" ON)

add_library(library_c STATIC)
target_sources(
    library_c
    PUBLIC
        FILE_SET HEADERS BASE_DIRS include FILES include/library_c/library_c.hpp
    PRIVATE src/library_c.cpp
)

if(LIBRARY_C_MODULES)
    add_library(library_c.module STATIC)
    target_sources(
        library_c.module
        PUBLIC
            FILE_SET CXX_MODULES BASE_DIRS src/ FILES src/library_c.cppm
            FILE_SET HEADERS
                BASE_DIRS include
                FILES include/library_c/library_c.hpp
    )
    target_compile_features(library_c.module PUBLIC cxx_std_23)
    if(CMAKE_CXX_MODULE_STD)
        message(STATUS "Build library_c with target PROPERTY CXX_MODULE_STD ON")
        set_target_properties(library_c.module PROPERTIES CXX_MODULE_STD 1)
        target_compile_definitions(library_c PUBLIC ABC_HAS_IMPORT_STD)
    endif()
    target_compile_definitions(
        library_c.module
        PUBLIC LIBRARY_C_ENABLE_MODULE_SUPPORT
    )
    add_library(abc::library_c.module ALIAS library_c.module)
endif()

add_library(abc::library_c ALIAS library_c)
