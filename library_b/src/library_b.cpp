#include <library_b/library_b.hpp>

namespace library_b {
  std::size_t describe() {
    return 42 + library_c::describe();
  }
}
