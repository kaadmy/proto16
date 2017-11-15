
#include "vm.h"

void vm_instruction_execute(vm_t *vm) {
  uint16_t *ip = &vm_register_get(vm, vm->registers[VM_REGISTER_IP])->word;

  printf("%hu\n", *ip);

  vm_instruction_t *instruction = (vm_instruction_t *) vm_mempool_get(vm, vm->mempools[VM_MEMPOOL_RAM], (size_t) *ip);
  vm_instruction_handler_f handler = vm->instruction_handlers[instruction->opcode];

  if (handler != NULL) { // Check for an unimplemented or no-op handler
    handler(vm, instruction);
  }

  *ip += offsetof(vm_instruction_t, operands);
  *ip += instruction->operand_num * 3; // Operand meta (byte) + operand value (word)

  printf("B: %hu\n", *ip);
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

  printf("Jumpy!");

  uint16_t *ip = &vm_register_get(vm, vm->registers[VM_REGISTER_IP])->word;

  *ip = vm_helper_get_u16_from_operand(vm, instruction, 0);
}
