
#include "c_local.h"

/*
  In order of byte importance, 0 = lowest
  LE: 01, 0123
  BE: 10, 3210

  Byte getters assume the input number is LE
 */

// Assignee endian swap functions

uint16_t (*c_to_le_word)(uint16_t num);
uint16_t (*c_from_le_word)(uint16_t num);

// Endian swap functions

static uint16_t word_swap(uint16_t num) {
  return ((num >> 8) | (num << 8));
}

static uint16_t word_nop(uint16_t num) {
  return num;
}

// Assignee byte getters

uint8_t (*c_byte0_from_word)(uint16_t num);
uint8_t (*c_byte1_from_word)(uint16_t num);

static uint8_t byte0_from_word(uint16_t num) {
  return ((num & 0xf0) << 8);
}

static uint8_t byte1_from_word(uint16_t num) {
  return (num & 0xf);
}

// Byte getters

// Check endianness of machine

void c_endian_check(void) {
  union { // TODO: Does this work or is using a string to check the better method?
    uint16_t num;
    uint8_t upper; // Upper byte
  } tester;

  tester.num = 1;

  if (tester.upper == 0) { // System is little endian
    c_to_le_word = word_nop;
    c_from_le_word = word_nop;

    c_byte0_from_word = byte0_from_word;
    c_byte1_from_word = byte1_from_word;
  } else { // Big endian
    c_to_le_word = word_swap;
    c_from_le_word = word_swap;

    c_byte0_from_word = byte1_from_word;
    c_byte1_from_word = byte0_from_word;
  }
}
