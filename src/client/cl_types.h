
#pragma once

#include <SDL2/SDL.h>

#include "common/common.h"
#include "vm/vm.h"
#include "renderer/renderer.h"
#include "sound/sound.h"

// Locals

#ifdef _CL_LOCAL

// Global state

typedef struct {
  bool exit;

  int32_t window_width, window_height;
  SDL_Window *window;

  vm_t *vm;
} cl_global_state_t;

#endif // _CL_LOCAL
