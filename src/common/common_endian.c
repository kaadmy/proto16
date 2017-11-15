
#include "common.h"

// Assignee endian swap functions

uint16_t (*common_endian_big_u16)(uint16_t number);
uint16_t (*common_endian_native_u16)(uint16_t number);

// Endian swap functions

uint16_t u16_swap(uint16_t number) {
  return ((number >> 8) | (number << 8));
}

uint16_t u16_nop(uint16_t number) {
  return number;
}

// Check endianness of machine

void common_endian_check(void) {
  union {
    uint16_t number;
    uint8_t upper; // Upper byte
  } tester;

  tester.number = 1;

  if (tester.upper == 0) { // Little endian
    common_endian_big_u16 = u16_swap;
    common_endian_native_u16 = u16_swap;
  } else { // Big endian
    common_endian_big_u16 = u16_nop;
    common_endian_native_u16 = u16_nop;
  }
}
