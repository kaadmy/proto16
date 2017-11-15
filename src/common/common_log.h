
#pragma once

typedef enum {
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_FATAL
} log_level_t;

void common_log_level(log_level_t level);
void common_log(log_level_t level, char *message);
