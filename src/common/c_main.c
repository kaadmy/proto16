
#include "c_local.h"

char *c_stringf(const char *format, ...) {
  // Difficult to use dynamic allocation since you can't ensure this will be safely freed
  static char strings[8][C_MAX_STRING_LENGTH];
  static uint8_t index;

  char *string = strings[(index ++) % 8];

  va_list args;

  va_start(args, format);
  vsnprintf(string, C_MAX_STRING_LENGTH, format, args);
  va_end(args);

  return string;
}
