
cmake_minimum_required(VERSION 2.8)

# Change binary location

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Setup binary

set(MAIN_SOURCES
  main.c)

add_executable(proto16
  ${MAIN_SOURCES})

target_link_libraries(proto16
  ${COMMON_LIBRARIES}
  ${VM_LIBRARIES}
  ${RENDERER_LIBRARIES}
  ${SOUND_LIBRARIES})
