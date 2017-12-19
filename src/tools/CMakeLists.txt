
# Change binary location

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Setup binary

set(TOOLS_SOURCES
  t_main.c)

add_executable(proto16-tools
  ${TOOLS_SOURCES})

target_link_libraries(proto16-tools
  ${COMMON_LIBRARIES})
