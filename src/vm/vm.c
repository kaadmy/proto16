
#include "vm.h"

vm_t *vm_init(uint32_t clockspeed) {
  vm_t *vm = malloc(sizeof(vm_t));
  DEBUG_ASSERT(vm != NULL);

  vm->clockspeed = clockspeed;

  vm->mempools_num = 0;
  vm->registers_num = 0;

  return vm;
}

void vm_deinit(vm_t *vm) {
  for (uint8_t i = 0; i < vm->mempools_num; i ++) {
    vm_mempool_free(vm, vm->mempools[i]);
  }

  for (uint8_t i = 0; i < vm->registers_num; i ++) {
    vm_register_free(vm, vm->registers[i]);
  }

  free(vm);
}

void vm_cycle(vm_t *vm, uint8_t substeps) {
  for (uint8_t i = 0; i < substeps; i ++) { // FIXME: Probably a more efficient way to do this?
    vm_instruction_execute(vm);

  // TODO: Implement CPU timer/delay
  }
}

void vm_set_instruction_handler(vm_t *vm, uint8_t opcode, vm_instruction_handler_f handler) {
  vm->instruction_handlers[opcode] = handler;
}

void vm_add_mempool(vm_t *vm, vm_mempool_t *mempool) {
  vm->mempools[vm->mempools_num] = mempool;
  vm->mempools_num ++;
}

void vm_add_register(vm_t *vm, vm_register_t *reg) {
  vm->registers[vm->registers_num] = reg;
  vm->registers_num ++;
}

void vm_load_test_program(vm_t *vm) {
  uint8_t *data = vm_mempool_get(vm, vm->mempools[VM_MEMPOOL_RAM], 0);

  data[0] = 0x00; // Operand num: 0
  data[1] = 0x00; // Opcode: 0

  data[2] = 0x01; // Operand num: 1
  data[3] = 0x01; // Opcode: 1
  data[4] = 0x22; // Operand flags: [type:pointer, size:word]
  data[5] = 0x00; // 1st byte of data: 0
  data[6] = 0x00; // 2nd byte of data: 0
}

void vm_error(vm_t *vm, char *message) {
  // TODO: When string formatting works, also display IP and possibly the stack etc
  common_logn(LOG_LEVEL_ERROR, message);
}
