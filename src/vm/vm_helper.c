
#include "vm.h"

uint8_t vm_helper_get_u8_from_operand(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num) {
  // No safety checks, do that yourself
  uint8_t operand_type = (instruction->operands[operand_num] & 0x30) >> 4; // 00110000

  uint16_t value = 0; // Max operand data size; in this case a word

  if (operand_type == VM_OPERAND_TYPE_CONSTANT) {
    value = instruction->operands[operand_num + 1]; // Byte meta, word data (cast down)
  } else if (operand_type == VM_OPERAND_TYPE_REGISTER) {
    value = vm_register_get(vm, vm->registers[VM_REGISTER_IP])->byte;
  } else {
    value = (uint8_t) vm_mempool_get(vm, vm->mempools[VM_MEMPOOL_RAM], instruction->operands[operand_num + 1]);
    // TODO: Memory read speed limitation
  }

  return (uint8_t) value; // Cast down 16-bit values if needed
}

uint16_t vm_helper_get_u16_from_operand(vm_t *vm, vm_instruction_t *instruction, uint8_t operand_num) {
  // No safety checks, do that yourself
  uint8_t operand_type = (instruction->operands[operand_num] & 0x30) >> 4; // 00110000
  uint8_t operand_size = (instruction->operands[operand_num] & 0x0f); // 00001111

  uint16_t value = 0;

  if (operand_type == VM_OPERAND_TYPE_CONSTANT) {
    value = instruction->operands[operand_num + 1]; // Byte meta, word data
  } else if (operand_type == VM_OPERAND_TYPE_REGISTER) {
    value = vm_register_get(vm, vm->registers[VM_REGISTER_IP])->byte;
  } else {
    value = (uint16_t) vm_mempool_get(vm, vm->mempools[VM_MEMPOOL_RAM], instruction->operands[operand_num + 1]);
    // TODO: Memory read speed limitation
  }

  if (operand_size == SIZE_BYTE) { // Cast to 8-bit value if requested
    return (uint8_t) value;
  } else {
    return value;
  }
}
