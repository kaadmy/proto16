
#pragma once

#include "c_types.h"

void c_log_level(c_log_level_t level);
void c_log(c_log_level_t level, const char *message);
void c_logn(c_log_level_t level, const char *message);
