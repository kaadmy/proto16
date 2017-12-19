
#include "t_local.h"

// Global state

t_global_state_t t_global_state;

// Init function

static void t_init(void) {
}

// Shutdown function

static void t_deinit(void) {
}

// Entrypoint

int main(int argc, char **argv) {
  c_endian_check(); // Determine system endian

  c_log_level(C_LOG_LEVEL_INFO);
  c_log(C_LOG_LEVEL_INFO, ENGINE_TOOLS_TITLE " v" ENGINE_VERSION_STRING "\n");

  if (atexit(t_deinit)) {
    c_log(C_LOG_LEVEL_FATAL, "Unable to assign exit handler\n");
  }

  t_init();

  exit(EXIT_SUCCESS);
}
