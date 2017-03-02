project(repl)

include_directories(${CMAKE_SOURCE_DIR}/src/)

set(sources
  main.cpp
)

add_executable(morph-repl ${sources})
target_link_libraries(morph-repl morphcore)
