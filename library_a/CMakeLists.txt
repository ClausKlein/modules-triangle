cmake_minimum_required(VERSION 4.2...4.3)

project(library_a LANGUAGES CXX)

option(
    LIBRARY_A_USE_LIBRARY_C_AS_MODULE
    "Use Library C as a module"
    ${LIBRARY_C_MODULES}
)

add_library(library_a STATIC)
add_library(abc::library_a ALIAS library_a)
target_sources(library_a PUBLIC FILE_SET CXX_MODULES FILES src/library_a.cppm)
if(LIBRARY_A_USE_LIBRARY_C_AS_MODULE)
    target_link_libraries(library_a PUBLIC library_b library_c.module)
else()
    target_link_libraries(library_a PUBLIC library_b library_c)
endif()
target_compile_features(library_a PUBLIC cxx_std_23)
if(CMAKE_CXX_MODULE_STD)
    message(STATUS "Build library_a with target PROPERTY CXX_MODULE_STD ON")
    set_target_properties(library_a PROPERTIES CXX_MODULE_STD 1)
    target_compile_definitions(library_a PUBLIC ABC_HAS_IMPORT_STD)
endif()
