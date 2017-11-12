
# Include libraries

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Setup library

set(RENDERER_SOURCES
  renderer.c)

add_library(renderer
  ${RENDERER_SOURCES})

target_link_libraries(renderer
  ${COMMON_LIBRARIES}
  ${SDL2_LIBRARIES})
