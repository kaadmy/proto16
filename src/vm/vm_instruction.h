
#pragma once

#include "vm.h"

// Call the next instruction

void vm_instruction_execute(vm_t *vm);

// Instruction handlers

void vm_instruction_handler_jmp(vm_t *vm, vm_instruction_t *instruction);
