
#pragma once

#include "vm.h"

vm_mempool_t *vm_mempool_alloc(size_t size);
void vm_mempool_free(vm_mempool_t *mempool);
void *vm_mempool_read(vm_mempool_t *mempool, size_t index, size_t size);
