project(browser)

include_directories(${CMAKE_SOURCE_DIR}/src/core)

set(sources
  main.cpp
)

add_executable(morphbrowser ${sources})
target_link_libraries(morphbrowser morphcore)
