
cmake_minimum_required(VERSION 2.8)

project(proto16 C)

# Options

option(BUILD_TOOLS "Build development tools" ON)

option(DEBUG_BUILD "Make a debug build" ON)
if(${DEBUG_BUILD})
  set(DEBUG_FLAGS "-O0 -g")
else()
  set(DEBUG_FLAGS "-O3")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra ${DEBUG_FLAGS}")

# Local shared includes

include_directories(src)

# Shared libraries

add_subdirectory(src/common)
set(COMMON_LIBRARIES common)

add_subdirectory(src/vm)
set(VM_LIBRARIES vm)

add_subdirectory(src/renderer)
set(RENDERER_LIBRARIES renderer)

add_subdirectory(src/sound)
set(SOUND_LIBRARIES sound)

add_subdirectory(src/client)

if(${BUILD_TOOLS})
  add_subdirectory(src/tools)
endif()
