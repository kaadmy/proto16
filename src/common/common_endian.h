
#pragma once

#include "common.h"

extern uint16_t (*common_endian_big_u16)(uint16_t number);
extern uint16_t (*common_endian_native_u16)(uint16_t number);

void common_endian_check(void);
