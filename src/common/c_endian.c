
#include "c_local.h"

// Assignee endian swap functions

uint16_t (*c_endian_toleu16)(uint16_t num);
uint16_t (*c_endian_fromleu16)(uint16_t num);

// Endian swap functions

static uint16_t u16_swap(uint16_t num) {
  return ((num >> 8) | (num << 8));
}

static uint16_t u16_nop(uint16_t num) {
  return num;
}

// Check endianness of machine

void c_endian_check(void) {
  union { // TODO: Does this work or is using a string to check the better method?
    uint16_t num;
    uint8_t upper; // Upper byte
  } tester;

  tester.num = 1;

  if (tester.upper == 0) { // Little endian
    c_endian_toleu16 = u16_nop;
    c_endian_fromleu16 = u16_nop;
  } else { // Big endian
    c_endian_toleu16 = u16_swap;
    c_endian_fromleu16 = u16_swap;
  }
}
