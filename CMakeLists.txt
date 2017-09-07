cmake_minimum_required(VERSION 3.6)
project(tetra)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set (tetra_VERSION_MAJOR 0)
set (tetra_VERSION_MINOR 1)
#TODO: check for terminator existence


set(TERMINATOR_PLUGIN_DIR "~/.config/terminator/plugins")
set(TRANSLATOR_SOURCES translator/Translator.cpp translator/google_undocumented/GoogleUdApiWrapper.cpp)
set(TRANSLATOR_HEADERS translator/Translator.h translator/google_undocumented/GoogleUdApiWrapper.h)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

add_library(google_wrapper SHARED ${TRANSLATOR_SOURCES})




add_custom_target(TEST_TARGET)
add_custom_command(TARGET TEST_TARGET PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy tetra.py ${TERMINATOR_PLUGIN_DIR}/tetra.py)