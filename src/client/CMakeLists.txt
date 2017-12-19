
# Change binary location

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Setup binary

set(CLIENT_SOURCES
  cl_event.c
  cl_main.c
  cl_window.c)

add_executable(proto16
  ${CLIENT_SOURCES})

target_link_libraries(proto16
  ${COMMON_LIBRARIES}
  ${VM_LIBRARIES}
  ${RENDERER_LIBRARIES}
  ${SOUND_LIBRARIES})
