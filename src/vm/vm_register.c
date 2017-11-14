
#include "vm.h"

vm_register_t *vm_register_alloc(uint8_t size) {
  vm_register_t *reg = malloc(sizeof(vm_register_t));
  DEBUG_ASSERT(reg != NULL);

  reg->size = size;

  return reg;
}

void vm_register_free(vm_register_t *reg) {
  free(reg);
}

vm_register_value_t *vm_register_get(vm_register_t *reg) {
  return &reg->value;
}
