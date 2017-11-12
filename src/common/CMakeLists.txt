
# Setup library

set(COMMON_SOURCES
  common.c
  log.c)

add_library(common
  ${COMMON_SOURCES})

target_link_libraries(common
  m) # Math
