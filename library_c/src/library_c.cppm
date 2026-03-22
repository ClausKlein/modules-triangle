module;

#ifndef ABC_HAS_IMPORT_STD
    #include <iostream>
#else
import std;
#endif

// NOTE: Including headers after import is not well-supported from clang++! CK
export module library_c;

#define LIBRARY_C_INCLUDED_FROM_INTERFACE_UNIT

extern "C++" {
export {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winclude-angled-in-module-purview"
#include "library_c.cpp"
#pragma clang diagnostic pop
}
}
