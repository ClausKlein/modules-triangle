cmake_minimum_required(VERSION 4.2...4.3)

project(library_b LANGUAGES CXX)

option(
    LIBRARY_B_USE_LIBRARY_C_AS_MODULE
    "Use Library C as a module"
    ${LIBRARY_C_MODULES}
)

add_library(library_b STATIC)
target_sources(
    library_b
    PUBLIC
        FILE_SET HEADERS BASE_DIRS include FILES include/library_b/library_b.hpp
    PRIVATE src/library_b.cpp
)
if(LIBRARY_B_USE_LIBRARY_C_AS_MODULE)
    target_link_libraries(library_b PUBLIC library_c.module)
else()
    target_link_libraries(library_b PUBLIC library_c)
endif()
target_compile_features(library_b PUBLIC cxx_std_23)
add_library(abc::library_b ALIAS library_b)
