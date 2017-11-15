
#pragma once

#include "vm.h"

// Call the next instruction

void vm_instruction_execute(vm_t *vm);

// NOP
void vm_instruction_handler_nop(vm_t *vm, vm_instruction_t *instruction);
