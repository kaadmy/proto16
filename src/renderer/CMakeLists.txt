
# Include libraries

find_package(PkgConfig REQUIRED)

pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})

# Setup library

set(RENDERER_SOURCES
  r_main.c)

add_library(renderer
  ${RENDERER_SOURCES})

target_link_libraries(renderer
  ${COMMON_LIBRARIES}
  ${SDL2_LIBRARIES})
