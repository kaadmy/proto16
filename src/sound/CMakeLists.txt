
cmake_minimum_required(VERSION 2.8)

# Setup library

set(SOUND_SOURCES
  sound.c)

add_library(sound
  ${SOUND_SOURCES})

target_link_libraries(sound
  ${COMMON_LIBRARIES})
