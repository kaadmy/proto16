
#include "vm.h"

vm_mempool_t *vm_mempool_alloc(size_t size) {
  vm_mempool_t *mempool = malloc(sizeof(vm_mempool_t));
  DEBUG_ASSERT(mempool != NULL);

  mempool->data = calloc(1, size);
  DEBUG_ASSERT(mempool->data != NULL);

  mempool->size = size;

  return mempool;
}

void vm_mempool_free(vm_t *vm, vm_mempool_t *mempool) {
  free(mempool->data);
  free(mempool);
}

void *vm_mempool_get(vm_t *vm, vm_mempool_t *mempool, size_t index) {
  if (index > mempool->size) {
    vm_error(vm, "Memory pool %d access out of bounds (%d > %d)");
  }

  return (mempool->data + index);
}
