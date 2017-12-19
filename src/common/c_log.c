
#include "c_local.h"

static struct {
  c_log_level_t level;
} log_state_s;

void c_log_level(c_log_level_t level) {
  log_state_s.level = level;
}

void c_log(c_log_level_t level, const char *message) {
  if (level < log_state_s.level) {
    return;
  }

  printf("%s", message);

  if (level >= C_LOG_LEVEL_FATAL) {
    exit(EXIT_FAILURE);
  }
}

void c_logn(c_log_level_t level, const char *message) { // TODO: Remove this when proper inline string formatting works
  if (level < log_state_s.level) {
    return;
  }

  printf("%s\n", message);

  if (level >= C_LOG_LEVEL_FATAL) {
    exit(EXIT_FAILURE);
  }
}
