#pragma once

#include <cstddef>

#if LIBRARY_C_ENABLE_MODULE_SUPPORT
import library_c;
#else
// NOTE: Including headers after import is not well-supported from clang++! CK
    #include <library_c/library_c.hpp>
#endif

namespace library_b {
std::size_t describe();
}
