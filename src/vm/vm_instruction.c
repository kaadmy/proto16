
#include "vm.h"

void vm_instruction_execute(vm_t *vm) {
  uint16_t *ip = &vm_register_get(vm->registers[0])->word;

  printf("%hu\n", *ip);

  vm_instruction_t *instruction = (vm_instruction_t *) vm_mempool_get(vm->mempools[0], (size_t) *ip);
  vm_instruction_handler_f handler = vm->instruction_handlers[instruction->opcode];

  if (handler != NULL) { // Check for an unimplemented or no-op handler
    handler(vm, instruction);
  }

  *ip += offsetof(vm_instruction_t, operands);
  *ip += instruction->operand_num * 3; // Operand meta (byte) + operand value (word)

  printf("B: %hu\n", *ip);
}
