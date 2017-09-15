cmake_minimum_required(VERSION 3.6)
project(tetra)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wl,--no-undefined")
set (tetra_VERSION_MAJOR 0)
set (tetra_VERSION_MINOR 1)

set(Boost_USE_STATIC_LIBS     OFF)
set(Boost_USE_MULTITHREADED    ON)
find_package(Boost REQUIRED COMPONENTS python system thread regex)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif()
find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp 3 REQUIRED)
if (PYTHONLIBS_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
    link_directories(${PYTHON_LIBRARIES})
endif()

#TODO: check for terminator existence


set(TERMINATOR_PLUGIN_DIR "~/.config/terminator/plugins")
set(TRANSLATOR_SOURCES translator/Translator.cpp )
set(TRANSLATOR_HEADERS translator/Translator.h)
set(HTTPHELPER_SOURCES translator/HttpHelper.cpp)
set(HTTPHELPER_HEADERS translator/HttpHelper.h)
set(GOOGLEWRAPPER_SOURCES translator/google_undocumented/GoogleUdApiWrapper.cpp)
set(GOOGLEWRAPPER_HEADERS translator/google_undocumented/GoogleUdApiWrapper.h)




add_library(google_wrapper SHARED ${TRANSLATOR_SOURCES} ${HTTPHELPER_SOURCES} ${GOOGLEWRAPPER_SOURCES})
set_target_properties(google_wrapper PROPERTIES PREFIX "" SUFFIX ".pyd")
target_link_libraries(google_wrapper ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} )



add_custom_target(TEST_TARGET)
add_custom_command(TARGET TEST_TARGET PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy tetra.py ${TERMINATOR_PLUGIN_DIR}/tetra.py)