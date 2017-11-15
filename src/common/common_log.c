
#include "common.h"

static struct {
  log_level_t level;
} log_state_s;

void common_log_level(log_level_t level) {
  log_state_s.level = level;
}

void common_log(log_level_t level, char *message) {
  if (level < log_state_s.level) {
    return;
  }

  printf("%s", message);
}

void common_logn(log_level_t level, char *message) { // TODO: Remove this when proper inline string formatting works
  if (level < log_state_s.level) {
    return;
  }

  printf("%s\n", message);
}
