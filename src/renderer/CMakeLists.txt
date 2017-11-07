
cmake_minimum_required(VERSION 2.8)

# Setup library

set(RENDERER_SOURCES
  renderer.c)

add_library(renderer
  ${RENDERER_SOURCES})

target_link_libraries(renderer
  ${COMMON_LIBRARIES})
