
#include "r_local.h"

r_global_state_t r_global_state;

void r_init(SDL_Window *window) {
  r_global_state.renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (r_global_state.renderer == NULL) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to create renderer, aborting\n");
  }

  SDL_RenderSetLogicalSize(r_global_state.renderer, R_FRAMEBUFFER_WIDTH, R_FRAMEBUFFER_HEIGHT);
  SDL_RenderSetIntegerScale(r_global_state.renderer, SDL_TRUE);

  r_global_state.framebuffer_texture = SDL_CreateTexture(r_global_state.renderer,
                                                         SDL_PIXELFORMAT_RGB888,
                                                         SDL_TEXTUREACCESS_STREAMING,
                                                         R_FRAMEBUFFER_WIDTH,
                                                         R_FRAMEBUFFER_HEIGHT);

  if (r_global_state.framebuffer_texture == NULL) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to create framebuffer texture, aborting\n");
  }

  r_global_state.framebuffer_pixels = malloc(R_FRAMEBUFFER_WIDTH * R_FRAMEBUFFER_HEIGHT * sizeof(uint32_t));
}

void r_deinit(void) {
  free(r_global_state.framebuffer_pixels);

  SDL_DestroyTexture(r_global_state.framebuffer_texture);
  SDL_DestroyRenderer(r_global_state.renderer);
}

void r_update(void) {
  SDL_SetRenderDrawColor(r_global_state.renderer, 0, 0, 0, 255);
  SDL_RenderClear(r_global_state.renderer);

  r_global_state.framebuffer_pixels[(1 * R_FRAMEBUFFER_WIDTH) + 3] = 0xffff00;

  SDL_UpdateTexture(r_global_state.framebuffer_texture, NULL, r_global_state.framebuffer_pixels, R_FRAMEBUFFER_WIDTH * sizeof(uint32_t));

  SDL_RenderCopy(r_global_state.renderer, r_global_state.framebuffer_texture, NULL, NULL);
}

void r_postupdate(void) {
  SDL_RenderPresent(r_global_state.renderer);
}
