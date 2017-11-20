
#include "common/common.h"
#include "vm/vm.h"

// CPU state

struct {
  vm_t *vm;

  vm_mempool_t *mempool_ram;
  vm_mempool_t *mempool_rom;

  vm_register_t *register_ip;
  vm_register_t *register_flags;
  vm_register_t *register_sp;
  vm_register_t *register_bp;
  vm_register_t *register_ax;
  vm_register_t *register_bx;
  vm_register_t *register_cx;
  vm_register_t *register_dx;
} cpu_state;

// Prototypes

void main_update(void);

void main_init(void) {
  // Initialize VM

  cpu_state.vm = vm_init(30000000); // 30,000,000 instructions per second (30MHz)

  // Initialize memory pools

  cpu_state.mempool_ram = vm_mempool_alloc(KBYTE_TO_BYTE(64)); // 64KB of RAM
  vm_add_mempool(cpu_state.vm, cpu_state.mempool_ram);

  cpu_state.mempool_rom = vm_mempool_alloc(MBYTE_TO_BYTE(32)); // 32MB of ROM
  vm_add_mempool(cpu_state.vm, cpu_state.mempool_rom);

  // Initialize registers

  cpu_state.register_ip = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_ip);

  cpu_state.register_flags = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_flags);

  cpu_state.register_sp = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_sp);

  cpu_state.register_bp = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_bp);

  cpu_state.register_ax = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_ax);

  cpu_state.register_bx = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_bx);

  cpu_state.register_cx = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_cx);

  cpu_state.register_dx = vm_register_alloc(SIZE_WORD);
  vm_add_register(cpu_state.vm, cpu_state.register_dx);

  // TODO: support sub-registers

  // Initialize opcodes

  vm_set_instruction_handler(cpu_state.vm, 1, vm_instruction_handler_jmp);

  // Use test program

  vm_load_test_program(cpu_state.vm);

  // "Start" CPU

  while (1) {
    main_update();
  }
}

void main_deinit(void) {
  vm_deinit(cpu_state.vm);
}

void main_update(void) {
  vm_step(cpu_state.vm);
}

int main(int argc, char **argv) {
  common_endian_check(); // Determine system endian

  common_log_level(LOG_LEVEL_INFO);
  common_log(LOG_LEVEL_INFO, ENGINE_TITLE " v" ENGINE_VERSION_STRING "\n");

  main_init();

  main_deinit();
}
