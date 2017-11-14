
#pragma once

#include "common/common.h"

#include "vm_types.h"
#include "vm_instruction.h"
#include "vm_mempool.h"
#include "vm_register.h"

vm_t *vm_init(uint32_t clockspeed);
void vm_deinit(vm_t *vm);
void vm_set_instruction_handler(vm_t *vm, uint8_t opcode, vm_instruction_handler_f handler);
void vm_add_mempool(vm_t *vm, vm_mempool_t *mempool);
void vm_add_register(vm_t *vm, vm_register_t *reg);
