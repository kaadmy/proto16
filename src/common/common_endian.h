
#pragma once

#include "common.h"

extern uint16_t (*common_endian_tobeu16)(uint16_t number);
extern uint16_t (*common_endian_frombeu16)(uint16_t number);

void common_endian_check(void);
