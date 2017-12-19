
#include "cl_local.h"

void cl_event_update(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch(event.type) {
    case SDL_QUIT:
      cl_exit();
      break;
    case SDL_KEYDOWN:
      break;
    case SDL_KEYUP:
      break;
    default:
      c_log(C_LOG_LEVEL_DEBUG, c_stringf("Unrecognized SDL event type %d, skipping\n", event.type));
      break;
    }
  }
}
