
# Setup library

set(VM_SOURCES
  vm.c)

add_library(vm
  ${VM_SOURCES})

target_link_libraries(vm
  ${COMMON_LIBRARIES})
