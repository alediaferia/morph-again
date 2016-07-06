cmake_minimum_required(VERSION 3.5.0)

project(morph-again)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

#
# find_package(Threads REQUIRED)
#
# # Enable ExternalProject CMake module
# include(ExternalProject)
#
# # Download and install GoogleTest
# ExternalProject_Add(
#     gtest
#     URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
#     PREFIX ${CMAKE_BINARY_DIR}/lib/gtest
#     # Disable install step
#     INSTALL_COMMAND ""
# )
#
# # Create a libgtest target to be used as a dependency by test programs
# add_library(libgtest IMPORTED STATIC GLOBAL)
# add_dependencies(libgtest gtest)
#
# # Set gtest properties
# ExternalProject_Get_Property(gtest source_dir binary_dir)
# set_target_properties(libgtest PROPERTIES
#     "IMPORTED_LOCATION" "${binary_dir}/libgtest.a"
#     "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
#     "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
# )
# # I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
# #include_directories("${source_dir}/include")
#
# # Download and install GoogleMock
# ExternalProject_Add(
#     gmock
#     URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
#     PREFIX ${CMAKE_BINARY_DIR}/lib/gmock
#     # Disable install step
#     INSTALL_COMMAND ""
# )
#
# # Create a libgmock target to be used as a dependency by test programs
# add_library(libgmock IMPORTED STATIC GLOBAL)
# add_dependencies(libgmock gmock)
#
# # Set gmock properties
# ExternalProject_Get_Property(gmock source_dir binary_dir)
# set_target_properties(libgmock PROPERTIES
#     "IMPORTED_LOCATION" "${binary_dir}/lib/gmock/libgmock.a"
#     "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
#     "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
# )
# # I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
# #include_directories("${CMAKE_BINARY_DIR}/include")

add_subdirectory(src)
# add_subdirectory(test)

include_directories(lib)
