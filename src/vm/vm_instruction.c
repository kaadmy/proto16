
#include "vm.h"

void vm_instruction_next(vm_t *vm, vm_instruction_t *instruction) {
  uint16_t ip = vm_register_get(vm, vm->registers[VM_REGISTER_IP])->word;

  ip += VM_INSTRUCTION_SIZE;
  ip += instruction->operand_num * VM_OPERAND_SIZE;

  vm->registers[VM_REGISTER_IP]->value.word = ip;
}

void vm_instruction_execute(vm_t *vm) {
  uint16_t ip = vm_register_get(vm, vm->registers[VM_REGISTER_IP])->word;

  vm_instruction_t *instruction = (vm_instruction_t *) vm_mempool_get(vm, vm->mempools[VM_MEMPOOL_RAM], (size_t) ip);
  vm_instruction_handler_f handler = vm->instruction_handlers[instruction->opcode];

  //  printf("[OP=%d IP=%d]\n", instruction->opcode, ip);

  if (handler == NULL) { // Check for an unimplemented or no-op handler
    vm_instruction_next(vm, instruction);

    return;
  }

  handler(vm, instruction);
}

// Miscellaneous commonly-used functions

static void needs_operands(vm_t *vm, vm_instruction_t *instruction, uint8_t min_operands) {
  if (instruction->operand_num < min_operands) {
    vm_error(vm, "Not enough operands");
  }
}

// Instruction handlers

void vm_instruction_handler_jmp(vm_t *vm, vm_instruction_t *instruction) {
  /*
    Opcode identifier: JMP

    Minimum operands: 1
    Maximum used operands: 1

    Action: IP = Op0
   */

  needs_operands(vm, instruction, 1);

  uint16_t ip = vm_register_get(vm, vm->registers[VM_REGISTER_IP])->word;

  //  printf(" IP before jump: %d\n", ip);

  ip = vm_helper_getopu16(vm, instruction, 0);

  //  printf(" IP after jump: %d\n", ip);

  vm->registers[VM_REGISTER_IP]->value.word = ip;
}
