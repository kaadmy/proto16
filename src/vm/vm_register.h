
#pragma once

#include "vm.h"

vm_register_t *vm_register_alloc(uint8_t size);
void vm_register_free(vm_register_t *reg);
vm_register_value_t *vm_register_get(vm_register_t *reg);
