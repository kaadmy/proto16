
# Setup library

set(COMMON_SOURCES
  c_color.c
  c_endian.c
  c_log.c
  c_main.c)

add_library(common
  ${COMMON_SOURCES})

target_link_libraries(common
  m # Math
  dl) # Dynamic libraries
