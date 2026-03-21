#pragma once

#if LIBRARY_C_ENABLE_MODULE_SUPPORT
import library_c;
#else
#include <library_c/library_c.hpp>
#endif
#include <cstddef>

namespace library_b {
    std::size_t describe();
}
