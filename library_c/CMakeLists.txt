cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

project(library_c LANGUAGES CXX)

option(LIBRARY_C_MODULES "Build library_c with C++20 module support" ON)

add_library(library_c STATIC)
    target_sources(library_c
        PUBLIC
            FILE_SET HEADERS
                BASE_DIRS include
                FILES
                    include/library_c/library_c.hpp
        PRIVATE
            src/library_c.cpp
    )
target_include_directories(library_c PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(LIBRARY_C_MODULES)
  add_library(library_c.module STATIC)
  target_sources(library_c.module
    PUBLIC FILE_SET CXX_MODULES
    BASE_DIRS src/
    FILES src/library_c.cppm
  )
  target_include_directories(library_c.module PUBLIC ${PROJECT_SOURCE_DIR}/include)
  target_compile_features(library_c.module PUBLIC cxx_std_23)
  set_target_properties(library_c.module PROPERTIES CXX_MODULE_STD 1)
  target_compile_definitions(library_c.module PUBLIC LIBRARY_C_ENABLE_MODULE_SUPPORT)
endif()
