
#pragma once

#include "vm.h"

// Operand helpers

uint8_t vm_helper_getop(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num); //
uint8_t vm_helper_getoptype(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num);
uint8_t vm_helper_getopsize(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num);
uint8_t vm_helper_getopu8(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num);
uint16_t vm_helper_getopu16(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num);
