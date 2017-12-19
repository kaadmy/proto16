
#pragma once

#include "r_types.h"

#ifdef _R_LOCAL

extern r_global_state_t r_global_state;

#endif // _R_LOCAL

void r_init(SDL_Window *window);
void r_deinit(void);

void r_update(void);
void r_postupdate(void);
