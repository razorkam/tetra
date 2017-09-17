cmake_minimum_required(VERSION 3.6)
project(tetra)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wl,--no-undefined")
set (tetra_VERSION_MAJOR 0)
set (tetra_VERSION_MINOR 1)

find_package(Threads REQUIRED)

set(Boost_USE_STATIC_LIBS     OFF)
set(Boost_USE_MULTITHREADED    ON)
set(Boost_ADDITIONAL_VERSIONS "1.65" "1.65.0")
set(Python_ADDITIONAL_VERSIONS 3.5)
find_package(Boost REQUIRED COMPONENTS python3 system thread regex)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

find_package(PythonLibs 3.5 REQUIRED)
find_package(PythonInterp 3.5 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARIES})

MESSAGE(STATUS ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

#TODO: check for terminator existence


set(TERMINATOR_PLUGIN_DIR "~/.config/terminator/plugins")
set(TRANSLATOR_SOURCES translator/Translator.cpp )
set(TRANSLATOR_HEADERS translator/Translator.h)
set(HTTPHELPER_SOURCES translator/HttpHelper.cpp)
set(HTTPHELPER_HEADERS translator/HttpHelper.h)
set(GOOGLEWRAPPER_SOURCES translator/google_undocumented/GoogleUdApiWrapper.cpp)
set(GOOGLEWRAPPER_HEADERS translator/google_undocumented/GoogleUdApiWrapper.h)




add_library(tetra_translator SHARED ${TRANSLATOR_SOURCES} ${HTTPHELPER_SOURCES} ${GOOGLEWRAPPER_SOURCES})
#set_target_properties(tetra_translator PROPERTIES PREFIX "" SUFFIX ".pyd")
target_link_libraries(tetra_translator ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(google_wrapper -lpython3.5m -lboost_system -lboost_python3 ${CMAKE_THREAD_LIBS_INIT})



add_custom_target(INSTALL_TETRA)
add_custom_command(TARGET INSTALL_TETRA PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy tetra.py ${TERMINATOR_PLUGIN_DIR}/tetra.py)