
cmake_minimum_required(VERSION 2.8)

# Setup library

set(COMMON_SOURCES
  common.c
  log.c)

add_library(common
  ${COMMON_SOURCES})

target_link_libraries(common
  m) # Math
