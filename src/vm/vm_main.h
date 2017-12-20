
#pragma once

#include "vm_types.h"

vm_t *vm_alloc(void);
void vm_free(vm_t *vm);

void vm_set_instruction_handler(vm_t *vm, uint8_t index, vm_instruction_handler_f func);

void vm_frame_bump(vm_frame_t *frame);
void vm_frame_exec(vm_frame_t *frame);

void vm_stack_bump(vm_frame_t *frame);

void vm_test_setup(vm_t *vm);
