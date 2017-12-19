
#include "vm_local.h"

void vm_instruction_nop(vm_frame_t *frame) {
}

void vm_instruction_push(vm_frame_t *frame) {
  vm_frame_bump();
}
