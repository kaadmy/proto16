
# Include libraries

find_package(PkgConfig REQUIRED)

pkg_search_module(SDL2_mixer REQUIRED SDL2_mixer)
include_directories(${SDL2_mixer_INCLUDE_DIRS})

# Setup library

set(SOUND_SOURCES
  s_main.c)

add_library(sound
  ${SOUND_SOURCES})

target_link_libraries(sound
  ${COMMON_LIBRARIES}
  ${SDL2_mixer_LIBRARIES})
