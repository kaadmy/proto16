
#pragma once

#include "c_types.h"

extern uint16_t (*c_endian_toleu16)(uint16_t number);
extern uint16_t (*c_endian_fromleu16)(uint16_t number);

void c_endian_check(void);
