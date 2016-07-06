project(core)

set(sources
  parser.cpp
  attribute.cpp
)

add_library(morphcore STATIC ${sources})
