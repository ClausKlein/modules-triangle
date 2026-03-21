cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD 1)

project(library_b LANGUAGES CXX)

option(LIBRARY_B_USE_LIBRARY_C_AS_MODULE "Use Library C as a module" ON)

add_library(library_b STATIC)
target_sources(library_b
    PUBLIC
        FILE_SET HEADERS
            BASE_DIRS include
            FILES include/library_b/library_b.hpp
    PRIVATE
        src/library_b.cpp
)
target_include_directories(library_b PUBLIC include)
if (LIBRARY_B_USE_LIBRARY_C_AS_MODULE)
  target_link_libraries(library_b PUBLIC library_c.module)
else()
  target_link_libraries(library_b PUBLIC library_c)
endif()
target_compile_features(library_b PUBLIC cxx_std_23)
