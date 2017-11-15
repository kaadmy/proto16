
# Setup library

set(COMMON_SOURCES
  common.c
  common_endian.c
  common_log.c)

add_library(common
  ${COMMON_SOURCES})

target_link_libraries(common
  m) # Math
