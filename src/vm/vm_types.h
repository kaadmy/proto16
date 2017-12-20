
#pragma once

#include "common/common.h"

// Sizes

#define VM_MAX_INSTRUCTIONS 256 // Maximum number of instructions; uint16
#define VM_INSTRUCTION_SIZE 1 // Size of a single instruction in bytes; [instruction:uint8]
#define VM_INSTRUCTION_DATA_SIZE 2 // Size of instruction data in bytes; [data:uint16]

#define VM_MAX_STACK 65536 // Maximum size of the stack in bytes; uint16

#define VM_RAM_SIZE 16777216 // RAM footprint; represented as uint32 in code but is limited to uint8 + uint16 (16MB)

// Types

#define VM_TYPE_UBYTE 0
#define VM_TYPE_SBYTE 1
#define VM_TYPE_UWORD 2
#define VM_TYPE_SWORD 3

// Prototype

struct vm_s;

// Stack value

typedef struct {
  uint8_t flags;
  uint16_t data;
} vm_stack_value_t; // Must be 3 bytes long

// State to run a full instruction; can be modified to change program state
// Basically superfluous since it has access to the VM, but looks nicer and is easier to use

typedef struct {
  struct vm_s *vm;

  uint32_t ip;

  uint16_t batch_left; // Remaining instructions left in this execute batch

  union {
    uint8_t ubyte;
    int8_t sbyte;
    uint16_t uword;
    int16_t sword;
  } data;
} vm_frame_t;

// Instruction handler

typedef void (*vm_instruction_handler_f) (vm_frame_t *frame);

// Main VM state

typedef struct vm_s {
  bool initialized;

  vm_instruction_handler_f instruction_handlers[VM_MAX_INSTRUCTIONS];

  uint16_t stack_ptr;
  vm_stack_value_t *stack;

  uint8_t *ram;

  vm_frame_t *frame;
} vm_t;
