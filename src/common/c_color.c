

#include "c_local.h"

bool c_color_equal(const c_color_t a, const c_color_t b) {
  if (a.r != b.r || a.g != b.g || a.b != b.b || a.a != b.a) {
    return false;
  }

  return true;
}
