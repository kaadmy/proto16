
#include "vm.h"

void vm_instruction_execute(vm_t *vm, vm_instruction_t *instruction) {
  vm_instruction_handler_f handler = vm->instruction_handlers[instruction->opcode];

  if (handler != NULL) {
    handler(vm, instruction);
  }
}
