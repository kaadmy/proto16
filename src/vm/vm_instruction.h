
#pragma once

#include "vm.h"

// Call the next instruction
void vm_instruction_execute(vm_t *vm);

// Bump IP and get ready for the next instruction; jumps can't use this
void vm_instruction_next(vm_t *vm, vm_instruction_t *instruction);

// Instruction handlers

void vm_instruction_handler_jmp(vm_t *vm, vm_instruction_t *instruction);
