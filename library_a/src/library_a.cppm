module;

#include <library_c/library_c.hpp>
#include <library_b/library_b.hpp>

export module library_a;

import std;

#if LIBRARY_C_ENABLE_MODULE_SUPPORT
import library_c;
#endif

namespace library_a {
    std::size_t describe() {
        return 42 + library_c::describe() + library_b::describe();
    }
}
