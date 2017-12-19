
#include "cl_local.h"

void cl_window_init(void) {
  if (SDL_VideoInit(NULL) == -1) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to initialize SDL video, aborting\n");
  }

  cl_global_state.window = SDL_CreateWindow(ENGINE_TITLE,
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            R_FRAMEBUFFER_WIDTH * 4,
                                            R_FRAMEBUFFER_HEIGHT * 4,
                                            SDL_WINDOW_MOUSE_FOCUS);

  if (cl_global_state.window == NULL) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to create window, aborting\n");
  }
}

void cl_window_deinit(void) {
  SDL_DestroyWindow(cl_global_state.window);

  SDL_VideoQuit();
}

void cl_window_postupdate(void) {
}
