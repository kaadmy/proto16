
#include "vm.h"

vm_t *vm_init(uint32_t clockspeed) {
  vm_t *vm = malloc(sizeof(vm_t));
  DEBUG_ASSERT(vm != NULL);

  vm->mempools_num = 0;
  vm->registers_num = 0;

  vm->clockspeed = clockspeed;

  return vm;
}

void vm_deinit(vm_t *vm) {
  for (uint8_t i = 0; i < vm->mempools_num; i ++) {
    vm_mempool_free(vm->mempools[i]);
  }

  for (uint8_t i = 0; i < vm->registers_num; i ++) {
    vm_register_free(vm->registers[i]);
  }

  free(vm);
}

void vm_add_mempool(vm_t *vm, vm_mempool_t *mempool) {
  vm->mempools[vm->mempools_num] = mempool;
  vm->mempools_num ++;
}

void vm_add_register(vm_t *vm, vm_register_t *reg) {
  vm->registers[vm->registers_num] = reg;
  vm->registers_num ++;
}
