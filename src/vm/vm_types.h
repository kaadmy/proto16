
#pragma once

// Limits

#define VM_MAX_OPCODES 256 // 256 is the absolute maximum; uint8
#define VM_MAX_MEMPOOLS 32 // 256 is the absolute maximum; uint8
#define VM_MAX_REGISTERS 32 // 256 is the absolute maximum; uint8

// Default indices

#define VM_MEMPOOL_RAM 0 // 0th mempool is RAM

#define VM_REGISTER_IP 0 // 0th register is IP

// Prototypes

struct vm_s;

// Instructions

typedef struct {
  uint8_t operand_num;
  uint8_t opcode;
  uint8_t *operands;
} vm_instruction_t;

typedef void (*vm_instruction_handler_f) (struct vm_s *vm, vm_instruction_t *instruction);

// Mempool

typedef struct {
  size_t size;
  void *data;
} vm_mempool_t;

// Register

typedef union {
  uint8_t byte; // Byte
  uint16_t word; // Word
} vm_register_value_t;

typedef struct {
  uint8_t size;
  vm_register_value_t value;
} vm_register_t;

// VM

typedef struct vm_s {
  uint32_t clockspeed;

  vm_instruction_handler_f instruction_handlers[VM_MAX_OPCODES];

  vm_mempool_t *mempools[VM_MAX_MEMPOOLS];
  uint8_t mempools_num;

  vm_register_t *registers[VM_MAX_REGISTERS];
  uint8_t registers_num;
} vm_t;

// Operand types

typedef enum {
  VM_OPERAND_TYPE_CONSTANT,
  VM_OPERAND_TYPE_REGISTER,
  VM_OPERAND_TYPE_POINTER
} vm_operand_type_t;
