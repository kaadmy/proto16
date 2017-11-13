
#include "common/common.h"
#include "vm/vm.h"

vm_t *cpu_vm;

int main(int argc, char **argv) {
  common_log_level(LOG_LEVEL_INFO);
  common_log(LOG_LEVEL_INFO, ENGINE_TITLE " v" ENGINE_VERSION_STRING "\n");

  // Start VM

  cpu_vm = vm_init(30000000); // 30,000,000 instructions per second (30MHz)

  vm_mempool_t *mempool = vm_mempool_alloc(KBYTE_TO_BYTE(64)); // 64KB of RAM
  vm_add_mempool(cpu_vm, mempool);

  mempool = vm_mempool_alloc(MBYTE_TO_BYTE(32)); // 32MB of ROM
  vm_add_mempool(cpu_vm, mempool);

  vm_deinit(cpu_vm);
}
