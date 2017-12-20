
#include "vm_local.h"

// Allocation and freeing

vm_t *vm_alloc(void) {
  vm_t *vm = malloc(sizeof(vm_t));
  if (vm == NULL) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to allocate VM, aborting\n");
  }

  vm->initialized = true;

  // Initialize all instruction handlers to no-op by default

  for (uint8_t i = (VM_MAX_INSTRUCTIONS - 1); i != 0; i--) {
    vm->instruction_handlers[i] = vm_instruction_nop;
  }

  // Stack

  vm->stack_ptr = 0;

  vm->stack = calloc(1, VM_MAX_STACK * sizeof(vm_stack_value_t));
  if (vm->stack == NULL) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to allocate stack for VM, aborting\n");
  }

  // RAM

  vm->ram = calloc(1, VM_RAM_SIZE);
  if (vm->ram == NULL) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to allocate RAM for VM, aborting\n");
  }

  // Allocate and initialize the VM frame

  vm->frame = malloc(sizeof(vm_frame_t));
  if (vm->frame == NULL) {
    c_log(C_LOG_LEVEL_FATAL, "Failed to allocate state frame for VM, aborting\n");
  }

  vm->frame->vm = vm;

  vm->frame->ip = 0; // Instruction pointer
  vm->frame->batch_left = 0; // Instructions left to execute for this batch

  vm->frame->data.uword = 0; // Zero data

  return vm;
}

void vm_free(vm_t *vm) {
  if (vm == NULL || !vm->initialized) {
    c_log(C_LOG_LEVEL_ERROR, "Cannot free VM that is not allocated, skipping\n");
    return;
  }

  vm->initialized = false;

  free(vm->stack);

  free(vm->ram);

  free(vm);
}

// Instruction handlers

void vm_set_instruction_handler(vm_t *vm, uint8_t index, vm_instruction_handler_f func) {
  vm->instruction_handlers[index] = func;
}

// Frame handling

void vm_frame_bump(vm_frame_t *frame) { // Note that there is no batch limit checking
  frame->ip += VM_INSTRUCTION_SIZE;
}

void vm_frame_exec(vm_frame_t *frame) {
  frame->batch_left--;
  if (frame->batch_left == 0) {
  }
  frame->vm->instruction_handlers[frame->data.ubyte](frame);
}

// Stack handling

void vm_stack_bump(vm_frame_t *frame) { // Increase stack pointer and do nothing else
  frame->vm->stack_ptr += sizeof(vm_stack_value_t);
}

// Test functions

void vm_test_setup(vm_t *vm) {
  // Testing code

  uint8_t *data = vm->ram;

  data[0] = 0x00; // NOP

  data[1] = 0x03; // PUSH
  data[1] = VM_TYPE_UBYTE; // Type: unsigned byte
  data[2] = 0x00; // 0x00

  data[3] = 0x01; // JUMP
}
