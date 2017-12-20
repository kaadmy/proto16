
#pragma once

#include "c_types.h"

extern uint16_t (*c_to_le_word)(uint16_t num);
extern uint16_t (*c__from_le_word)(uint16_t num);

extern uint8_t (*c_byte0_from_word)(uint16_t num);
extern uint8_t (*c_byte1_from_word)(uint16_t num);

void c_endian_check(void);
