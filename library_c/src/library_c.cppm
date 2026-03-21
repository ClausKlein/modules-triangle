export module library_c;

import std;

#define LIBRARY_C_INCLUDED_FROM_INTERFACE_UNIT

extern "C++" {
export {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winclude-angled-in-module-purview"
  #include "library_c.cpp"
#pragma clang diagnostic pop
}
}
