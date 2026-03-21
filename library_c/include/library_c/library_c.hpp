#pragma once

#if !defined(LIBRARY_C_ENABLE_MODULE_SUPPORT) || defined(LIBRARY_C_INCLUDED_FROM_INTERFACE_UNIT)

#include <cstddef>

namespace library_c {
  std::size_t describe();
}

#endif
