cmake_minimum_required(VERSION 3.6)
project(TETRA)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
#TODO: check for terminator existence

add_custom_target(TEST_TARGET)
set(TERMINATOR_PLUGIN_DIR "~/.config/terminator/plugins")
add_custom_command(TARGET TEST_TARGET PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy tetra.py ${TERMINATOR_PLUGIN_DIR}/tetra.py)