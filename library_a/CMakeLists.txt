cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD 1)

project(library_a LANGUAGES CXX)

option(LIBRARY_A_USE_LIBRARY_C_AS_MODULE "Use Library C as a module" ON)

add_library(library_a STATIC)
target_sources(library_a
    PUBLIC
        FILE_SET CXX_MODULES FILES
            src/library_a.cppm
)
if (LIBRARY_A_USE_LIBRARY_C_AS_MODULE)
  target_link_libraries(library_a PUBLIC library_b library_c.module)
else()
  target_link_libraries(library_a PUBLIC library_b library_c)
endif()
target_compile_features(library_a PUBLIC cxx_std_23)
