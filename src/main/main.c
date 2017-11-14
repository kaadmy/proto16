
#include "common/common.h"
#include "vm/vm.h"

struct {
  vm_t *vm;
  vm_mempool_t *mempool_ram;
  vm_mempool_t *mempool_rom;
} cpu_state;

void main_init(void) {
  // Start VM

  cpu_state.vm = vm_init(30000000); // 30,000,000 instructions per second (30MHz)

  cpu_state.mempool_ram = vm_mempool_alloc(KBYTE_TO_BYTE(64)); // 64KB of RAM
  vm_add_mempool(cpu_state.vm, cpu_state.mempool_ram);

  cpu_state.mempool_rom = vm_mempool_alloc(MBYTE_TO_BYTE(32)); // 32MB of ROM
  vm_add_mempool(cpu_state.vm, cpu_state.mempool_rom);
}

void main_deinit(void) {
  vm_deinit(cpu_state.vm);
}

int main(int argc, char **argv) {
  common_log_level(LOG_LEVEL_INFO);
  common_log(LOG_LEVEL_INFO, ENGINE_TITLE " v" ENGINE_VERSION_STRING "\n");
}
