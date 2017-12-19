
#pragma once

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "version.h"

// Limits

#define C_MAX_STRING_LENGTH 2048 // Dynamically allocated, this is a soft limit. u16 for string length

// Log levels

typedef enum {
  C_LOG_LEVEL_DEBUG, // Stuff the user should not need to see
  C_LOG_LEVEL_INFO, // Stuff the user should see a lot
  C_LOG_LEVEL_WARNING, // Stuff the user shouldn't need to care about
  C_LOG_LEVEL_ERROR, // Stuff the user should notice
  C_LOG_LEVEL_FATAL // Stuff the user will notice
} c_log_level_t;

// Color

typedef struct {
  float r, g, b, a;
} c_color_t;
