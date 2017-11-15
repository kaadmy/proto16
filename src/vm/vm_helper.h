
#pragma once

#include "vm.h"

uint8_t vm_helper_get_u8_from_operand(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num);
uint16_t vm_helper_get_u16_from_operand(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num);
