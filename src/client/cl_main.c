
#include "cl_local.h"

// Global state

cl_global_state_t cl_global_state;

// Prototypes

static void cl_update(void);

// Init function

static void cl_init(void) {
  cl_global_state.vm = vm_alloc();

  vm_test_setup(cl_global_state.vm);

  if (SDL_Init(0) == -1) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to initialize SDL, aborting\n");
  }

  cl_window_init();

  r_init(cl_global_state.window);

  while (!cl_global_state.exit) {
    cl_update();
  }
}

// Shutdown function

static void cl_deinit(void) {
  r_deinit();

  cl_window_deinit();

  SDL_Quit();

  vm_free(cl_global_state.vm);
}

// Soft exit function

void cl_exit(void) {
  cl_global_state.exit = true;
}

// Single frame update

static void cl_update(void) {
  cl_event_update();

  r_update();

  r_postupdate();

  cl_window_postupdate();
}

// Entrypoint

int main(int argc, char **argv) {
  c_endian_check(); // Determine system endian

  c_log_level(C_LOG_LEVEL_INFO);
  c_log(C_LOG_LEVEL_INFO, ENGINE_TITLE " v" ENGINE_VERSION_STRING "\n");

  if (atexit(cl_deinit)) {
    c_log(C_LOG_LEVEL_FATAL, "Unable to assign exit handler\n");
  }

  cl_init();

  exit(EXIT_SUCCESS);
}
