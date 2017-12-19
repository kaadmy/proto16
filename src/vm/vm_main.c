
#include "vm_local.h"

// Allocation and freeing

void vm_alloc(vm_t *vm) {
  vm = malloc(sizeof(vm_t));
  assert(vm != NULL);

  // Initialize all instruction handlers to no-op by default

  for (uint8_t i = VM_MAX_INSTRUCTIONS - 1; i != 0; i --) {
    vm->instruction_handlers[i] = vm_instruction_nop;
  }

  // Zero stack

  memset(vm->stack, 0, VM_MAX_STACK * sizeof(vm_stack_value_t));
  vm->stack_ptr = 0;

  // Zero RAM

  memset(vm->ram, 0, VM_RAM_SIZE);

  // Allocate and initialize the VM frame

  vm->frame = malloc(sizeof(vm_frame_t));
  assert(vm->frame != NULL);

  vm->frame->ip = 0;
  vm->frame->batch_left = 0;
}

void vm_free(vm_t *vm) {
  free(vm);
}

// Instruction handlers

void vm_set_instruction_handlers(vm_t *vm, uint8_t index, vm_instruction_handler_f func) {
  vm->instruction_handlers[index] = func;
}

// Frame handling

void vm_frame_bump(vm_frame_t *frame) { // Note that there is no batch limit checking
  frame->ip += VM_INSTRUCTION_SIZE;
}

void vm_frame_exec(vm_frame_t *frame) {
  frame->vm->instruction_handlers[frame->data.ubyte](frame);
}

// Stack handling

void vm_stack_bump(vm_frame_t *frame) { // Increase stack pointer and do nothing else
  frame->vm->stack_ptr += sizeof(vm_stack_value_t);
}
