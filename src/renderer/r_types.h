
#pragma once

#include <SDL2/SDL.h>

#include "common/common.h"

// Constants

#define R_FRAMEBUFFER_WIDTH 180
#define R_FRAMEBUFFER_HEIGHT 135

// Begin locals

#ifdef _R_LOCAL

// Global renderer state

typedef struct {
  SDL_Renderer *renderer;

  SDL_Texture *framebuffer_texture;
  uint32_t *framebuffer_pixels;
} r_global_state_t;

#endif // _R_LOCAL
