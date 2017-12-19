
#pragma once

#include "common/common.h"

// Sizes

#define VM_MAX_INSTRUCTIONS 256 // Maximum number of instructions; uint16
#define VM_INSTRUCTION_SIZE 1 // Size of a single instruction in bytes; [instruction:uint8]
#define VM_INSTRUCTION_DATA_SIZE 2 // Size of instruction data in bytes; [data:uint16]

#define VM_MAX_STACK 21845 // Maximum stack values; uint16 (64KB)
#define VM_STACK_VALUE_SIZE 3 // Size of a single stack value in bytes; [data:uint16, flags:uint8]

#define VM_RAM_SIZE 16777216 // RAM footprint; represented as uint32 in code but is limited to uint8 + uint16 (16MB)

// Prototype

struct vm_s;

// Stack value

typedef struct {
  uint16_t data;
  uint8_t flags;
} vm_stack_value_t;

// State to run a full instruction; can be modified to change program state
// Basically superfluous since it has access to the VM, but looks nicer and is easier to use

typedef struct {
  struct vm_s *vm;

  uint32_t ip;

  uint16_t batch_left; // Remaining instructions left in this execute batch

  union {
    uint8_t byte;
    int8_t sbyte;
    uint16_t word;
    int16_t sword;
  } data;
} vm_frame_t;

// Instruction handler

typedef void (*vm_instruction_handler_f) (vm_frame_t *frame);

// Main VM state

typedef struct vm_s {
  vm_instruction_handler_f instruction_handlers[VM_MAX_INSTRUCTIONS];

  vm_stack_value_t stack[VM_MAX_STACK];
  uint16_t stack_ptr;

  uint8_t ram[VM_RAM_SIZE];

  vm_frame_t *frame;
} vm_t;
