
#pragma once

#include "common/common.h"

#include "vm_mempool.h"
#include "vm_register.h"

#define VM_MAX_MEMPOOLS 32 // 256 is the absolute maximum; uint8
#define VM_MAX_REGISTERS 32 // 256 is the absolute maximum; uint8

typedef struct {
  uint32_t clockspeed;

  vm_mempool_t *mempools[VM_MAX_MEMPOOLS];
  uint8_t mempools_num;

  vm_register_t *registers[VM_MAX_REGISTERS];
  uint8_t registers_num;
} vm_t;

vm_t *vm_init(uint32_t clockspeed);
void vm_deinit(vm_t *vm);
void vm_add_mempool(vm_t *vm, vm_mempool_t *mempool);
void vm_add_register(vm_t *vm, vm_register_t *reg);
