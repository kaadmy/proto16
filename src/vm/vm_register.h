
#pragma once

#include "vm.h"

typedef union {
  uint8_t byte; // Byte
  uint16_t word; // Word
} vm_register_value_t;

typedef struct {
  uint8_t size;
  vm_register_value_t value;
} vm_register_t;

vm_register_t *vm_register_alloc(uint8_t size);
void vm_register_free(vm_register_t *reg);
vm_register_value_t *vm_register_get(vm_register_t *reg);
